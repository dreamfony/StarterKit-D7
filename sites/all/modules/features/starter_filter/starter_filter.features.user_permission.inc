<?php
/**
 * @file
 * starter_filter.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function starter_filter_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'use text format filtered_html'.
  $permissions['use text format filtered_html'] = array(
    'name' => 'use text format filtered_html',
    'roles' => array(),
    'module' => 'filter',
  );

  // Exported permission: 'use text format full_html'.
  $permissions['use text format full_html'] = array(
    'name' => 'use text format full_html',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'use text format full_html_raw'.
  $permissions['use text format full_html_raw'] = array(
    'name' => 'use text format full_html_raw',
    'roles' => array(),
    'module' => 'filter',
  );

  return $permissions;
}
