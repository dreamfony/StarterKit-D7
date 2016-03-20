; Drush API
api = 2

; Core Drupal
core = 7.x

includes[drupal] = make/core.make

; TODO create pantheon core make

; TODO Add performance patches create patches folder and copy them there
; projects[drupal][patch][995156] = http://drupal.org/files/issues/995156-5_portable_taxonomy_permissions.patch


defaults[projects][subdir] = contrib

; Modules - Utilities
; ====================================================
includes[utilities] = make/utilities.make

; Modules - Development
; ====================================================
;includes[development] = make/development.make

; Modules - Multilingual
; ====================================================
; includes[multilingual] = make/multilingual.make

; Modules - Commerce
; ====================================================
; includes[commerce] = make/commerce.make


; Themes
; ====================================================
;projects[] = "zen"


; Template for module descriptions
; ====================================================
; Title / Description
; Use: For configuration management.