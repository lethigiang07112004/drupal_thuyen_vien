<?php
if (isset($_SERVER['HTTP_HOST']) && strpos($_SERVER['HTTP_HOST'], 'tuyendung.localhost:8080') !== false) {

    if ($_SERVER['REQUEST_URI'] == '/' || $_SERVER['REQUEST_URI'] == '/index.html') {
        $file = __DIR__ . '/sites/tuyendung/static/pcf_index.php';

        if (file_exists($file)) {
            if (ob_get_level()) ob_end_clean();
             include($file);  
            exit;
        } else {
            die("Lỗi: Không tìm thấy file tại " . $file);
        }
    }
}


define('DRUPAL_ROOT', getcwd());
require_once DRUPAL_ROOT . '/includes/bootstrap.inc';
//require_once DRUPAL_ROOT . '/includes/entity.inc'; // Ép nạp file chứa class bị thiếu
drupal_bootstrap(DRUPAL_BOOTSTRAP_FULL);
menu_execute_active_handler();
