<?php

/**
 * Implements hook_features_banish_alter().
 */
function custom_config_features_banish_alter(&$features_banish) {
  global $conf;
  $keys = array_keys($conf);
  $features_banish['variable'][] = 'cron_last';
  $features_banish['variable'] = is_array($features_banish['variable']) ? $features_banish['variable'] : array();
  foreach ($keys as $key) {
    // Banish most of the annoying __active_tab variables.
    if (strpos($key, '__active_tab') !== FALSE OR strpos($key, 'custom_config_') !== FALSE) {
      $features_banish['variable'][] = $key;
    }
  }

//  Update documentation at https://www.drupal.org/node/2400531

//  Core
//  -------
//Changes when cron is run
  $features_banish['variable'][] = 'cron_last';
//Security: Allows for running cron.php remotely
  $features_banish['variable'][] = 'cron_key';
//  What install task the site is currently on.
  $features_banish['variable'][] = 'install_task';
//  Datestamp the site was installed.
  $features_banish['variable'][] = 'install_time';
//  Name of the install profile used for installing site
  $features_banish['variable'][] = 'install_profile';
//  An error flag when Drupal can't talk to the internet.
  $features_banish['variable'][] = 'drupal_http_request_fails';
//A list css files that are being cached by drupal
  $features_banish['variable'][] = 'drupal_css_cache_files';
//A list js files that are being cached by drupal
  $features_banish['variable'][] = 'drupal_js_cache_files';
//Cached parent-child relationships of menu items.
  $features_banish['variable'][] = 'menu_masks';
//the last timestamp when module updates were checked.
  $features_banish['variable'][] = 'update_last_check';
//the last timestamp when email about updates was sent.
  $features_banish['variable'][] = 'update_last_email_notification';
//list of parsed javascript files.
  $features_banish['variable'][] = 'javascript_parsed';
//Changes each time the css and jss cache is reset.
  $features_banish['variable'][] = 'css_js_query_string';
//Flag when the site is in maintenance mode.
  $features_banish['variable'][] = 'maintenance_mode';
//Private key used to generate tokens.
  $features_banish['variable'][] = 'drupal_private_key';
//Used to short-circuit path lookups
  $features_banish['variable'][] = 'path_alias_whitelist';

//Features
//--------
//Cached md5 hash of features export objects.
  $features_banish['variable'][] = 'features_codecache';
//Used to avoid race conditions.
  $features_banish['variable'][] = 'features_semaphore';
//Cache of orphaned features
  $features_banish['variable'][] = 'features_ignored_orphans';

//Other
//-------
//Ctools - used to cleanup old object caches.
  $features_banish['variable'][] = 'ctools_last_cron';
//Entity API - List of entity cache tables
  $features_banish['variable'][] = 'entity_cache_tables_created';
//l10n_update - Last time translation availability was checked
  $features_banish['variable'][] = 'l10n_update_last_check';
//l10n_update - Translation status of enabled modules
  $features_banish['variable'][] = 'l10n_update_translation_status';
//Module Filter - Recent modules timestamps
  $features_banish['variable'][] = 'module_filter_recent_modules';
//Environment - The currently enabled environment
  $features_banish['variable'][] = 'environment';
//Environment - The overridden environment
  $features_banish['variable'][] = 'environment_override';
//SMTP - Username
  $features_banish['variable'][] = 'smtp_username';
//SMTP - Password
  $features_banish['variable'][] = 'smtp_password';
//xmlsitemap - Last time the sitemap was generated
  $features_banish['variable'][] = 'xmlsitemap_generated_last';
//xmlsitemap - Whether the sitemap needs to be regenerated
  $features_banish['variable'][] = 'xmlsitemap_regenerate_needed';

//  Core - Performance Settings
  $features_banish['variable'][] = 'preprocess_js';
  $features_banish['variable'][] = 'preprocess_css';
  $features_banish['variable'][] = 'cache';
  $features_banish['variable'][] = 'page_cache_maximum_age';
  $features_banish['variable'][] = 'cache_lifetime';
//Core - Error reporting
  $features_banish['variable'][] = 'error_level';
  $features_banish['variable'][] = 'dblog_row_limit';
//Mail dev settings
  $features_banish['variable'][] = 'maillog_devel';
  $features_banish['variable'][] = 'maillog_log';
  $features_banish['variable'][] = 'maillog_send';
  $features_banish['variable'][] = 'mail_system';
//Menus
  $features_banish['menu_custom'][] = 'management';
  $features_banish['menu_custom'][] = 'features';
//
  $features_banish['menu_custom'][] = 'features';

}