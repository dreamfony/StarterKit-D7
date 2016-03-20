## HOW TO

    git clone starterKit
    drush make starter.make
    site install

## FEATURES

* grouped make files with recommended modules
	* see starter.make 
* forced best practice folder structure for custom, contrib, features etc.
* disabled unnecessary drupal modules like RDF, Overlay etc. 
* no content types, taxonomies etc.
* some variables set to best practice trough features (like features_default_export_path is set to modules/features)
* Role_export modul for proper exporting roles trough features
* Everything is in features, if u go to create new feature there will be nothing, things that should not be exported are removed using feature_banish modul.
	* see profiles/starterkit/modules/custom_config/includes/features_banish.inc
* ckeditor


## TODO

* best practice site building example (context + context_uuid)
* menu_import
* patch management - https://bitbucket.org/davereid/drush-patchfile
* Environment management (settings.local.php)  - https://www.drupal.org/project/habitat
* Configuration management (hook_update examples, etc)
