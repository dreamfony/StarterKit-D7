<?php
/**
 * @file
 * A .profile must exist in order for the profile to be picked up by Drupal.
 */

/**
 * Implements hook_form_FORM_ID_alter() for install_select_profile_form().
 *
 * Allows the profile to alter the site configuration form.
 */
function starterkit_form_install_configure_form_alter(&$form, $form_state) {
  // Set a default site name and email address.
  $form['site_information']['site_name']['#default_value'] = t('Starter');
  $form['site_information']['site_mail']['#default_value'] = 'admin@localhost.com';

  // Set a default username and email address.
  $form['admin_account']['account']['name']['#default_value'] = 'admin';
  $form['admin_account']['account']['mail']['#default_value'] = 'admin@localhost.com';

  // Set a default country and timezone.
  $form['server_settings']['site_default_country']['#default_value'] = 'US';
  $form['server_settings']['date_default_timezone']['#default_value'] = 'America/New_York';

  // Disable 'check for updates' and 'receive email notifications' check boxes.
  $form['update_notifications']['update_status_module']['#default_value'][0] = 0;
  $form['update_notifications']['update_status_module']['#default_value'][1] = 0;
}