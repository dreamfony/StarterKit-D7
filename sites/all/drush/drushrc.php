<?php
$backup_time = time();
$day_of_week = date('D',$backup_time);

$options['shell-aliases']['db-dump-dev'] = 'sql-dump --result-file=sites/all/db_dump/mysite_'.$day_of_week.'.sql  --structure-tables-key=common --gzip';

$options['shell-aliases']['db-dump-backup'] = 'sql-dump --result-file=/app/tmp/mysite_db_backup_'.$day_of_week.'.sql  --structure-tables-key=common --gzip';
$options['shell-aliases']['site-dump-backup'] = 'ard --destination=/app/tmp/mysite_full_backup_'.$day_of_week.'.tar --tar-options="--exclude=.git" --overwrite';
// Add tables to structure-only list
// Set default if it doesn't exist. Copied from example.drushrc.php
if (!isset($options['structure-tables']['common'])) {
  $options['structure-tables'] = array(
      'common' => array(
          'accesslog',
          'aggregator_item',
          'apachesolr_index_entities*',
          'apachesolr_search_node',
          'advagg_bundles',
          'cache',
          'cache_*',
          'captcha_sessions',
          'ctools_css_cache',
          'ctools_object_cache',
          'devel*',
          'flood',
          'history',
          'masquerade',
          'mollom',
          'migrate_*',
          'profile_values',
          'realname',
          'search*',
          'sessions',
          'sparql_store_*',
          'views_content_cache',
          'watchdog',
          'xmlsitemap',
      ),
  );

}