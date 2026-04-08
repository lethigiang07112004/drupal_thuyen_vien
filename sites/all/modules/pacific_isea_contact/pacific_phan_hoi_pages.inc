<?php
function pacific_phan_hoi_callback()
{
  if ($_SERVER['REQUEST_METHOD'] === 'POST' && empty($_POST) && !empty($_SERVER['CONTENT_LENGTH'])) {
    $max_upload = ini_get('upload_max_filesize');
    $max_post = ini_get('post_max_size');
    $limit = min($max_upload, $max_post, '2M');
    drupal_set_message(t('File bạn chọn quá lớn. Vui lòng chọn file nhỏ hơn @limit.', array('@limit' => $limit)), 'error');
  }
  $styles = drupal_get_css();
  $scripts = drupal_get_js();
  $form = drupal_get_form('pacific_isea_contact_ph_form');
  $form_output = drupal_render($form);
  $messages = theme('status_messages', array());
  $logo_path = file_create_url('/sites/all/modules/pacific_isea_contact/images/images1.jpg');
  $output = '<!DOCTYPE html>
  <html>
  <head>
    <title>Thông tin phản hồi từ thuyền viên - Pacific Manpower</title>
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta charset="utf-8">
    ' . $styles . '
    ' . $scripts . '
    <link rel="stylesheet" href="/' . drupal_get_path('module', 'pacific_isea_contact') . '/css/style.css">
    <link
        href="https://fonts.googleapis.com/css2?family=Playfair+Display:wght@400;600;700&family=Plus+Jakarta+Sans:wght@300;400;500;600;700&family=Roboto:ital,wght@0,100..900;1,100..900&display=swap"
        rel="stylesheet">
    <script src="/sites/all/modules/pacific_isea_contact/js/file_upload.js"></script>
  </head>
  <body>
   <div class="bg-pattern">
        <div class="bg-grid"></div>
    </div>
     <svg class="wave-decoration" viewBox="0 0 1440 320" preserveAspectRatio="none">
        <path fill="rgba(0, 93, 174, 0.03)"
            d="M0,160L48,176C96,192,192,224,288,213.3C384,203,480,149,576,138.7C672,128,768,160,864,186.7C960,213,1056,235,1152,218.7C1248,203,1344,149,1392,122.7L1440,96L1440,320L1392,320C1344,320,1248,320,1152,320C1056,320,960,320,864,320C768,320,672,320,576,320C480,320,384,320,288,320C192,320,96,320,48,320L0,320Z">
        </path>
    </svg>
    <div class="page-container">
    <header class="header">
            <div class="header-inner">
                <div class="brand">
                    <div class="logo-icon">
                        <img src="/sites/all/modules/pacific_isea_contact/images/lg.png" class="logo">
                    </div>
                    <span class="brand-text">Pacific Manpower</span>
                </div>

                <a href="/thong-tin" class="back-link">
                    <svg width="18" height="18" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2"
                        stroke-linecap="round" stroke-linejoin="round">
                        <line x1="19" y1="12" x2="5" y2="12" />
                        <polyline points="12 19 5 12 12 5" />
                    </svg>
                    Quay lại
                </a>
            </div>
        </header>
        
        <!-- Form Content -->
        <main class="form-container">
            <div class="form-header">
                <h1 class="form-title">Thông tin phản hồi từ thuyền viên</h1>
                <p class="form-subtitle">Vui lòng điền đầy đủ thông tin</p>
            </div>
            <div>' . (!empty($messages) ? '<div id="messages">' . $messages . '</div>' : '')

    . $form_output . '
                </main>
                </div>
                
  </body>
  </html>';
  print $output;
  var_dump($messages);
  drupal_page_footer();
}

/**
 * 3. Hàm định nghĩa Form 
 */
function pacific_isea_contact_ph_form($form, &$form_state)
{
  drupal_add_library('system', 'drupal.form');
  drupal_add_library('system', 'jquery.form');
  $form["#attributes"]['class'] = 'form-card';
  $form_fields = array(
    "Thông tin cá nhân" => array(
      'ho_ten' => array(
        '#type' => 'textfield',
        '#title' => t('Họ và tên'),
        '#required' => TRUE,
        '#attributes' => array('placeholder' => t('Nhập họ tên')),
      ),
      "chuc_danh" => array(
        '#type' => 'select',
        '#title' => t('Chức danh'),
        '#options' => array(
          '' => t('- CAPT -'),
          'CAPT' => t('CAPT'),
          'CO' => t('CO'),
          '2O' => t('2O'),
          '3O' => t('3O'),
          'BSN' => t('BSN'),
          'CARP' => t('CARP'),
          'AB' => t('AB'),
          'OSD' => t('OSD'),
          'DCADET' => t('DCADET'),
          'C.E' => t('C.E'),
          '2E' => t('2E'),
          '3E' => t('3E'),
          '4E' => t('4E'),
          'ETO' => t('ETO'),
          'ELECT' => t('ELECT'),
          'FTR' => t('FTR'),
          'OLR' => t('OLR'),
          'WPR' => t('WPR'),
          'ECADET' => t('ECADET'),
          'COOK' => t('COOK'),
          'MESS' => t('MESS'),
          'OSE' => t('OSE'),
          'OS' => t('OS'),
        ),
        '#required' => TRUE,
      ),
          
      'tau_vua_di' => array(
        '#type' => 'textfield',
        '#title' => t('Tàu vừa đi'),
        '#required' => TRUE,
        '#attributes' => array('placeholder' => t('Nhập tên tàu vừa đi')),
      ),
    ),


    "Thông tin phản hồi" => array(
      '#attributes' => array('class' => array('tt_phan_hoi')),
      'feeback' => array(
        '#type' =>  'textarea',
        '#title' => t('Thông tin phản hồi'),
        '#required' => TRUE,
        '#attributes' => array('placeholder' => t('Nhập thông tin phản hồi')),
      ),
    ),
    "Nguyện vọng - Mong muốn" => array(
      "chuc_danh_mong_muon" => array(
        '#type' => 'select',
        '#title' => t('Chức danh mong muốn'),
        '#options' => array(
          '' => t('- CAPT -'),
          'CAPT' => t('CAPT'),
          'CO' => t('CO'),
          '2O' => t('2O'),
          '3O' => t('3O'),
          'BSN' => t('BSN'),
          'CARP' => t('CARP'),
          'AB' => t('AB'),
          'OSD' => t('OSD'),
          'DCADET' => t('DCADET'),
          'C.E' => t('C.E'),
          '2E' => t('2E'),
          '3E' => t('3E'),
          '4E' => t('4E'),
          'ETO' => t('ETO'),
          'ELECT' => t('ELECT'),
          'FTR' => t('FTR'),
          'OLR' => t('OLR'),
          'WPR' => t('WPR'),
          'ECADET' => t('ECADET'),
          'COOK' => t('COOK'),
          'MESS' => t('MESS'),
          'OSE' => t('OSE'),
          'OS' => t('OS'),
        ),
        '#required' => TRUE,
      ),
      'thoi_gian_san_sang' => array(
        '#type' => 'textfield',
        '#title' => t('Thời gian sẵn sàng'),
        '#required' => TRUE,
        '#default_value' => '01/01/2001',
        '#attributes' => array(
          'class' => array('custom-datepicker-input'),
          'placeholder' => 'dd/mm/yyyy',
        ),
      ),  
      'size_tau_mong_muon' => array(
        '#type' => 'textfield',
        '#title' => t('Size tàu'),
        '#required' => TRUE,
        '#attributes' => array('placeholder' => t('Nhập size tàu mong muốn')),
      ),
      'loai_tau_group' => array(
        '#type' => 'container',
        '#attributes' => array(
          'class' => array('form-group'),
        ),
        'loai_tau_mong_muon' => array(
          '#type' => 'checkboxes',
          '#title' => t('Từng đi kinh nghiệm loại tàu nào rồi ?'),
          '#options' => array(
            'Tàu Bulk Carrier' => t('Tàu Bulk Carrier'),
            'Tàu Container' => t('Tàu Container'),
            'Tàu LPG' => t('Tàu LPG'),
            'Tàu Tank' => t('Tàu Tank'),
            'Tàu General Cargo' => t('Tàu General Cargo'),
            'Tàu Tàu Offshore' => t('Tàu Offshore'),
            'Tàu Passenger' => t('Tàu Passenger'),
            'Tàu pure car carrier' => t('Tàu pure car carrier'),
            'Khác' => t('Khác'),

          ),
        ),
        'ten_tau' => array(
          '#type' => 'textfield',
          '#attributes' => array('placeholder' => t('Nhập tàu')),
        ),
      ),
      'muc_luong_mong_muon' => array(
        '#type' => 'textfield',
        '#title' => t('Mức lương mong muốn'),
        '#required' => TRUE,
        '#attributes' => array('placeholder' => t('Nhập mức lương mong muốn')),
      ),
    ),

  );

  foreach ($form_fields as $group => $fields) {
    $form[$group] = array(
      '#type' => 'container',
      '#attributes' => array(
        'class' => array('form-section')
      ),
      'header' => array(

        '#markup' => '<div class="section-header"><div class="section-icon">
                            <svg width="20" height="20" viewBox="0 0 24 24" fill="none" stroke="currentColor"
                                stroke-width="2" stroke-linecap="round" stroke-linejoin="round">
                                <path d="M20 21v-2a4 4 0 0 0-4-4H8a4 4 0 0 0-4 4v2" />
                                <circle cx="12" cy="7" r="4" />
                            </svg>
                        </div>
                        <h2 class="section-title">' . t(ucfirst(str_replace('_', ' ', $group))) . '</h2></div>'
      ),
    );
    $form[$group]['grid'] = array(
      "#type" => 'container',
      '#attributes' => array(
        'class' => array('form-grid'),
      ),
    );
    foreach ($fields as $field_name => $field_info) {
      // if(isset($field_info['#attributes'])){
      //     if(isset($field_info['#attributes']['class'])){
      //       $field_info['#attributes']['class'][] = 'form-group';
      //     }else {
      //       $field_info['#attributes']['class'] = array (
      //         'form-group'
      //       );
      //     }
      //   }else{
      //     $field_info['#attributes'] = array(
      //       'class' => array('form-group')
      //     );
      //   }
      $field_info['#wrapper_attributes'] = array('class' => array('form-group'));
      $form[$group]['grid'][$field_name] = $field_info;
    }
  }

  // 1. Phần thông tin Hotline (Dùng Markup để viết HTML trực tiếp)
  $form['hotline_info'] = array(
    '#markup' => '
      <div class="hotline-container">
  <p>Hotline tư vấn, đào tạo, tuyển dụng thuyền viên</p>
  <div class="hotline-contacts">
    <div class="hotline-contact">
      <a href="tel:0366893485">0366.893.485</a>
      <span>- Ms Thu Trang (Zalo)</span>
    </div>
    <div class="hotline-contact">
      <a href="tel:0901518819">090.151.8819</a>
      <span>- Ms Thắm (Zalo)</span>
    </div>
    <div class="hotline-contact">
      <a href="tel:0904162189">0904.162.189</a>
      <span>- Ms Vân (Zalo)</span>
    </div>
  </div>
</div>',
  );
  // 2. Nhóm các nút điều hướng (Actions)
  $form['actions'] = array('#type' => 'actions');

  $form['actions']['back'] = array(
    '#markup' => l(
      t('Quay lại'),
      'thong-tin',
      array(
        'attributes' => array(
          'class' => array('btn-back')
        )
      )
    ),
  );

  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Gửi phản hồi'),
    '#submit' => array('pacific_isea_contact_ph_form_submit'),
    '#attributes' => array('class' => array('btn-gui-ho-so')),
  );

  $form['#attached']['library'][] = 'pacific_isea_contact/file-upload-lib';
  return $form;
}

/**
 * 4. Hàm xử lý submit 
 */
function pacific_isea_contact_ph_form_submit($form, &$form_state)
{
  $v = $form_state['values'];
   $loai_tau_mong_muon = !empty($v['loai_tau_mong_muon']) ? implode(', ', array_filter($v['loai_tau_mong_muon'])) : '';
  $tuoi_db = '';
  if (!empty($v['thoi_gian_san_sang'])) {
    // Chuyển từ dd/mm/yyyy sang yyyy-mm-dd
    $date_obj = DateTime::createFromFormat('d/m/Y', $v['thoi_gian_san_sang']);
    $tuoi_db = $date_obj ? $date_obj->format('Y-m-d') : '';
  }

  try {
    db_insert('isea_phan_hoi')
      ->fields(array(
        'chuc_danh' => $v['chuc_danh'],
        'ho_ten' => $v['ho_ten'],
        'tau_vua_di' => $v['tau_vua_di'],
        'feeback' => $v['feeback'],
        'chuc_danh_mong_muon' => $v['chuc_danh_mong_muon'],       
        'thoi_gian_san_sang' => $tuoi_db,
        'size_tau_mong_muon' => $v['size_tau_mong_muon'],
        'loai_tau_mong_muon' => $loai_tau_mong_muon,
        'ten_tau' => $v['ten_tau'],
        'muc_luong_mong_muon' => $v['muc_luong_mong_muon'],
        'created' => REQUEST_TIME,
      ))
      ->execute();



    drupal_set_message('Phản hồi đã được gửi thành công!');
    $_SESSION['isea_show_popup'] = TRUE;
  } catch (Exception $e) {
    drupal_set_message($e->getMessage(), 'error');
  }
}

/**
 * 3. Trang hiển thị danh sách trong Admin
 */
function pacific_isea_contact_admin_ph_list()
{
  $header = array(
    'ID',
    'Họ tên',
    'Chức danh',
    'Tàu vừa đi',
    'Phản hồi',
    'Chức danh mong muốn',
    'Thời gian sẵn sàng',
    'Size tàu mong muốn',
    'Loại tàu mong muốn',
    'Loại tàu mong muốn khác',
    'Mức lương mong muốn',
    'Ngày gửi'
  );
  $rows = array();

  $result = db_select('isea_phan_hoi', 't')
    ->fields('t')
    ->orderBy('created', 'DESC')
    ->execute();

  foreach ($result as $record) {
    
    $hien_thi_tuoi = '';
    if (!empty($record->thoi_gian_san_sang) && $record->thoi_gian_san_sang != '0000-00-00') {
      $hien_thi_tuoi = date('d/m/Y', strtotime($record->thoi_gian_san_sang));
    }
    $rows[] = array(
      $record->id,
      check_plain($record->ho_ten),
      check_plain($record->chuc_danh),
      check_plain($record->tau_vua_di),
      check_plain($record->feeback),
      check_plain($record->chuc_danh_mong_muon),
      $hien_thi_tuoi,
      check_plain($record->size_tau_mong_muon),
      check_plain($record->loai_tau_mong_muon),
      check_plain($record->ten_tau),
      check_plain($record->muc_luong_mong_muon),   
      format_date($record->created, 'short'),
    );
  }


  $link_export = l('📥 Xuất file Excel (CSV)', 'admin/phan-hoi/export', array('attributes' => array('style' => 'font-weight:bold; color:green;')));
  return $link_export . theme('table', array('header' => $header, 'rows' => $rows));
}


/**
 * 4. Hàm xuất CSV để mở bằng Excel
 */
function pacific_isea_contact_ph_export_csv()
{
  header('Content-Type: text/csv; charset=utf-8');
  header('Content-Disposition: attachment; filename=ds-thuyen_vien.csv');
  $fp = fopen('php://output', 'w');
  fprintf($fp, chr(0xEF) . chr(0xBB) . chr(0xBF));

  fputcsv($fp, array(
    'ID',
    'Họ tên',
    'Chức danh',
    'Tàu vừa đi',
    'Phản hồi',
    'Chức danh mong muốn',
    'Thời gian sẵn sàng',
    'Size tàu mong muốn',
    'Loại tàu mong muốn',
    'Loại tàu mong muốn khác',
    'Mức lương mong muốn',
    'Ngày gửi'
  ));
  $data = db_select('isea_phan_hoi', 't')->fields('t')->execute();
  foreach ($data as $r) {


    $csv_date = '';
    if (!empty($r->thoi_gian_san_sang) && $r->thoi_gian_san_sang != '0000-00-00') {
      $csv_date = date('d/m/Y', strtotime($r->thoi_gian_san_sang));
    }
    fputcsv($fp, array(
      $r->id,
      $r->ho_ten,
      $r->chuc_danh,
      $r->tau_vua_di,
      $r->feeback,
      $r->chuc_danh_mong_muon,
      $csv_date,
      $r->size_tau_mong_muon,
      $r->loai_tau_mong_muon,
      $r->ten_tau,
      $r->muc_luong_mong_muon,
      date('d/m/Y', $r->created)
    ));
  }
  fclose($fp);
}
