<?php

$markdown_library = DRUPAL_ROOT . '/' . drupal_get_path('module', MODULE_NAME) . '/includes/parsedown.php';
require_once $markdown_library;

class Carsedown extends Parsedown {

  protected function inlineImage($Excerpt) {
    $Image = parent::inlineImage($Excerpt);
    if ($Image != NULL) {
      $Image['element']['attributes']['src'] = variable_get('custom_config_instructions_folder') . 'images/' . $Image['element']['attributes']['src'];
    }
    return $Image;
  }
}

/**
 * Implements hook_form().
 */
function custom_config_admin_form($form, &$form_state) {
  $updates = get_new_updates();
  $updates = $updates[MODULE_NAME];
//  todo use theme function
  $markup = "<h1>Last commit: " . shell_exec("git log -1 --abbrev-commit --oneline") . "</h1>";
  $markup .= "<h2>Update module: " . MODULE_NAME . "</h2>";
  $markup .= "<h3>Last update (schema_version): " . $updates['schema_version'] . "</h3>";
  $markup .= "<h3>Instructions folder: " . INSTRUCTIONS_FOLDER . "</h3>";
  $markup .= "<h3>Clicky Keyword: " . CLICKY_KEYWORD . "</h3>";

  $form['#attached']['css'] = array(
    drupal_get_path('module', MODULE_NAME) . '/css/custom_config.css',
  );
  $form['last_commit'] = array(
    '#markup' => $markup,
  );
  if (isset($updates['non_pending'])) {
    $form['non_pending'] = array(
      '#type' => 'fieldset',
      '#title' => t('Settings already applied via update'),
      '#weight' => 1,
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
    );

    foreach ($updates['non_pending'] as $key => $value) {
      $function = MODULE_NAME . '_update_' . $key;
      $markup = '<h3>Description</h3>';
      $markup .= Carsedown::instance()
        ->setBreaksEnabled(TRUE)
        ->text($value['description']);
      $documentation_file = $_SERVER['DOCUMENT_ROOT'].INSTRUCTIONS_FOLDER . $function . '.txt';
      if (file_exists($documentation_file)) {
        $markup .= '<h3>Description found in .txt file</h3>';
        $Parsedown = new Carsedown();
        $markup .= $Parsedown->setBreaksEnabled(TRUE)
          ->text(file_get_contents($documentation_file));
      }
      // TODO ovo se tak ne prevađa
      $form['non_pending'][$function] = array(
        '#type' => 'fieldset',
        '#title' => t('/ ' . $function . ' / Run at: ' . date('d m y - H:i', variable_get($function))),
        '#collapsible' => TRUE,
        '#collapsed' => TRUE,
      );
      if (isset($value['needs_clicky'])) {
        $form['non_pending'][$function]['#attributes'] = array('class' => array('has_clicky'));
      }
      $form['non_pending'][$function]['description'] = array(
        '#markup' => $markup,
      );
    }


  }
  if (isset($updates['pending'])) {
    $form['pending'] = array(
      '#type' => 'fieldset',
      '#title' => t('New Settings that need update'),
      '#weight' => 2,
      '#collapsible' => FALSE,
      '#collapsed' => FALSE,
    );

    foreach ($updates['pending'] as $key => $value) {
      $function = MODULE_NAME . '_update_' . $key;
      //if is set var get i veći od 0 onda stavi i datum
      $markup = '<h3>Description</h3>';
      $markup .= Carsedown::instance()
        ->setBreaksEnabled(TRUE)
        ->text($value['description']);
      $documentation_file = INSTRUCTIONS_FOLDER . $function . '.txt';
      if (file_exists($documentation_file)) {
        $markup .= '<h3>Description found in .txt file</h3>';
        $Parsedown = new Carsedown();
        $markup .= $Parsedown->setBreaksEnabled(TRUE)
          ->text(file_get_contents($documentation_file));


      }
      // TODO ovo se tak ne prevađa
      $form['pending'][$function] = array(
        '#type' => 'fieldset',
        '#title' => t('Update name:' . $function . ''),
        '#collapsible' => TRUE,
        '#collapsed' => !isset($value['needs_clicky']),
      );
      $form['pending'][$function]['description'] = array(
        '#markup' => $markup,
      );
      if (isset($value['needs_clicky'])) {

        $form['pending'][$function]['actions']['#type'] = 'actions';
// todo Riješit ovo ajaxom
        $form['pending'][$function]['actions']['submit'] = array(
          '#type' => 'submit',
          '#value' => t('I have applied this settings'),
//          '#ajax' => array(
//            'callback' => 'custom_config_admin_form_submit',
//            'method' => 'replaceWith',
//            'event' => 'click',
//            'wrapper' => 'taxonomy-term-data-replace',
//          ),
        );
        $form['pending'][$function]['actions']['submit']['#name'] = $function;
      }
      else {
        $form['pending'][$function]['description2'] = array(
          '#markup' => 'This settings will be applied when u run update.php',
        );
      }
    }
  }


  if ($updates['needs_clicky'] != TRUE AND isset($updates['pending'])) {
    $form['run_update'] = array(
      '#markup' => t('<h1>Please run <a href="@url"> site update</a> to apply newest settings.</h1>', array('@url' => base_path() . 'update.php')),
      '#weight' => 100,
    );

  }
  elseif (!isset($updates['pending'])) {
    $form['run_update'] = array(
      '#markup' => t('<h1>HOORAY! NOTHING TO DO. SITE IS UP TO DATE.</h1>'),
      '#weight' => 100,
    );
  }

  $form ['#submit'][] = 'custom_config_admin_form_submit';

  return $form;
}

function custom_config_admin_form_submit(&$form, &$form_state) {
  variable_set($form_state['triggering_element']['#name'], 1);
}

function _custom_config_menus_configuration() {

  $documentation_file = $_SERVER['DOCUMENT_ROOT'] . INSTRUCTIONS_FOLDER . 'menu_link.txt';
  if (file_exists($documentation_file)) {
    $Parsedown = new Carsedown();
    $markup = $Parsedown->setBreaksEnabled(TRUE)
      ->text(file_get_contents($documentation_file));

    return $markup;
  }

}

/**
 * Implements hook_form().
 */
 
 function custom_config_settings($form, &$form_state) {
  
$form['custom_config_instructions_folder'] = array(
    '#type' => 'textfield',
    '#title' => t('Folder where updates.php resides'),
    '#default_value' => variable_get('custom_config_instructions_folder', ''),
  );


  return system_settings_form($form);
}
 