<?php
function thong_tin_callback() {
  $form_output = drupal_render($form);

$logo_path = file_create_url('/sites/all/modules/custom/images/images1.jpg');


  $current_date = date('d-m-Y'); 
  if (ob_get_level()) ob_end_clean();

$output = '<!DOCTYPE html>
  <html>
  <head>
    <title>PACIFIC MANPOWER</title>
    <meta charset="utf-8">
    <link rel="stylesheet" href="/' . drupal_get_path('module', 'isea_contact') . '/css/style.css">
  </head>


<body>
    <div class="min-h-screen bg-maritime">
        <div class="container">
            <div class="form-card welcome-card">
                <header class="form-header-1">
                    <h1 class="welcome-title">WELCOME TO PACIFIC MANPOWER</h1>
                </header>
                <div class="welcome-content">
                    <div class="logo-container">
                        <img src="' . $logo_path . '" class="welcome-logo">
                        <p class="brand-tagline">Happier with us</p>
                    </div>
                    <div class="welcome-buttons">
                        <a href="/gui-ho-so" class="welcome-button submit-info">
                            <span class="button-icon">📝</span> Gửi thông tin thuyền viên
                        </a>

                        <a href="/tuyen-sinh" class="welcome-button recruitment">
                            <span class="button-icon">💼</span> Tuyển sinh khóa sơ cấp tàu biển
                        </a>
                    </div>
                </div>
                <div class="form-footer">
                    <div class="status-item">
                        <span>📅</span>
                        <span>' . $current_date . '</span>
                    </div>
                </div>

            </div>
        </div>
    </div>
</body>

</html>';
  print $output;
  drupal_exit();
}
