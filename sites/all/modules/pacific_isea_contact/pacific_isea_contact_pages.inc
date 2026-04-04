<?php
function  pacific_isea_contact_callback() {
  $form = drupal_get_form('pacific_isea_contact_customer_form');
  //$messages = theme('status_messages'); 
  $form_output = drupal_render($form);

   $logo_path = file_create_url('/sites/all/modules/custom/images/images1.jpg');

  $output = '<!DOCTYPE html>
  <html>
  <head>
    <title>Liên hệ PACIFIC</title>
    <meta charset="utf-8">
    <link rel="stylesheet" href="' . drupal_get_path('module', 'pacific_isea_contact') . '/css/style.css">
    <script src="/sites/all/modules/pacific_isea_contact/js/file_upload.js"></script>
  </head>
  <body>
   <div class="min-h-screen bg-maritime">
        <div class="container">
            <div class="form-card">
                <header class="form-header">
                    <h1>WELCOME TO PACIFIC MANPOWER</h1>
                    <div class="header-content">
                        <img src="' . $logo_path . '" alt="SEN logo" class="SEN-logo">
                        <p>Mời bạn gửi thông tin thật chi tiết để PACIFIC MANPOWER có thể hỗ trợ bạn tốt nhất nhé! 😊</p>
                    </div>
                </header>
                <div class="standalone-container">
                 ' . $form_output . '
                </div>
            </div>
        </div>
    </div>
  </body>
  </html>';
  print $output;
  drupal_page_footer(); 
  
} 

/**
 * 3. Hàm định nghĩa Form 
 */
function pacific_isea_contact_customer_form($form, &$form_state) { 
   $form['group_basic_info'] = array(
    '#type' => 'container',
    '#attributes' => array(
      'class' => array('group-info-row'), 
    ),
  );

  $form['group_basic_info']['ho_ten'] = array(
    '#type' => 'textfield',
    '#title' => t('Họ và tên'),
    '#required' => TRUE,
    '#attributes' => array('placeholder' => t('Nhập họ tên')),
  );

/*
$days = drupal_map_assoc(range(1, 31));
$months = drupal_map_assoc(range(1, 12));
$years = drupal_map_assoc(range(1900, date('Y')));
$form['group_basic_info']['tuoi_container'] = array(
  '#type' => 'container',
);
$form['group_basic_info']['tuoi_container']['title'] = array(
  '#markup' => '<label>Bao nhiêu tuổi<span>*</span></label>',
);

// Tạo một wrapper phụ cho các select để giữ hàng ngang
$form['group_basic_info']['tuoi_container']['fields'] = array(
  '#type' => 'container',
  '#attributes' => array('style' => 'display: flex; align-items: center; gap: 8px;'),
);
$form['group_basic_info']['tuoi_container']['fields']['day'] = array(
  '#type' => 'select',
  '#options' => $days,
  '#default_value' => 1,
  '#attributes' => array('class' => array('no-arrow-select')), 
  '#suffix' => '<span class="delimiter">/</span>',
);

$form['group_basic_info']['tuoi_container']['fields']['month'] = array(
  '#type' => 'select',
  '#options' => $months,
  '#default_value' => 1,
  '#attributes' => array('class' => array('no-arrow-select')),
  '#suffix' => '<span class="delimiter">/</span>',
);

$form['group_basic_info']['tuoi_container']['fields']['year'] = array(
  '#type' => 'select',
  '#options' => $years,
  '#default_value' => 2000,
  '#attributes' => array('class' => array('no-arrow-select')),
);
*/
$form['group_basic_info']['tuoi'] = array(
  '#type' => 'textfield',
  '#title' => t('Bao nhiêu tuổi'),
  '#required' => TRUE,
  '#default_value' => '01/01/2001', 
  '#attributes' => array(
    'class' => array('custom-datepicker-input'),
    'placeholder' => 'dd/mm/yyyy',
  ),
);


  $form['group_basic_info']['sdt'] = array(
    '#type' => 'textfield',
    '#title' => t('Số điện thoại'),
    '#required' => TRUE,
    '#attributes' => array('placeholder' => t('Số điện thoại')),
  );

    $form['group_basic_info']['tinh_trang_hon_nhan'] = array(
    '#type' => 'select',
    '#title' => t('Tình trạng hôn nhân'),
     '#options' => array(
      '' => t('- Chọn tình trạng -'),
      'Độc thân' => t('Độc thân'),
      'Đã kết hôn' => t('Đã kết hôn'),
      'Đã ly hôn' => t('Đã ly hôn'),
    ),
    '#required' => TRUE,
  );

  $form['group_basic_info']['so_con'] = array(
    '#type' => 'textfield',
    '#title' => t('Số con (nếu có)'),
    '#required' => TRUE,
    '#attributes' => array('placeholder' => t('Nhập số con')),
  );

   $form['que_quan'] = array(
    '#type' => 'textfield',
    '#title' => t('Quê quán'),
    '#required' => TRUE,
    '#attributes' => array('placeholder' => t('Nhập thông tin')),
  );

  $form['group_basic_info_ht'] = array(
    '#type' => 'container',
    '#attributes' => array(
      'class' => array('group-info-row-2'), 
    ),
  );

  $form['group_basic_info_ht']['HoTenNguoiThan'] = array(
    '#type' => 'textfield',
    '#title' => t('Họ tên người bảo lãnh'),
    '#required' => TRUE,
    '#attributes' => array('placeholder' => t('Họ tên người bảo lãnh')),
  );

  $form['group_basic_info_ht']['MoiQuanHeNguoiThan'] = array(
    '#type' => 'select',
    '#title' => t('Mối quan hệ người bảo lãnh'),
     '#options' => array(
      '' => t('- Chọn mối quan hệ -'),
      'Bố' => t('Bố'),
      'Mẹ' => t('Mẹ'),
      'Vợ' => t('Vợ'),
      'Anh' => t('Anh'),
      'Chị' => t('Chị'),
      'Em' => t('Em'),
    ),
    '#required' => TRUE,
  );

   $form['group_basic_info_ht']['SDTNguoiThan'] = array(
    '#type' => 'textfield',
    '#title' => t('SĐT người bảo lãnh'),
    '#required' => TRUE,
    '#attributes' => array('placeholder' => t('SĐT người bảo lãnh')),
  );

  $form['group_basic_info_ht']['hoc_van'] = array(
    '#type' => 'select',
    '#title' => t('Trình độ học vấn?'),
     '#options' => array(
      '' => t('- Chọn thông tin -'),
      'THCS' => t('THCS'),
      'THPT' => t('THPT'),
      'SƠ CẤP' => t('SƠ CẤP'),
      'TRUNG CẤP' => t('TRUNG CẤP'),
      'CAO ĐẲNG' => t('CAO ĐẲNG'),
      'ĐẠI HỌC' => t('ĐẠI HỌC'),
    ),
    '#required' => TRUE,
  );

  $form['group_basic_info_ht']['ngon_ngu'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Bạn biết những ngôn ngữ nào?'),
    '#options' => array(
      'Tiếng Anh' => t('Tiếng Anh'),
      'Tiếng Trung' => t('Tiếng Trung'),
    ),
  );
  $form['group_basic_info_ht']['group_basic_info_ld'] = array(
    '#type' => 'container',
    '#attributes' => array(
      'class' => array('group-info-row-1'), 
    ),
  );

  $form['group_basic_info_ht']['group_basic_info_ld']['ld_nuoc_ngoai'] = array(
    '#type' => 'radios',
    '#title' => t('Từng đi lao động ở nước ngoài chưa? / Nước nào?'),
    '#options' => array(
      '1' => t('Có'),
      '0' => t('Không'),
    ),
    '#required' => TRUE, // Tạo dấu sao đỏ (*)
  );

  $form['group_basic_info_ht']['group_basic_info_ld']['ten_nuoc_chi_tiet'] = array(
    '#type' => 'textfield',
    '#attributes' => array(
      'placeholder' => t('Nhập tên nước đã lao động'),
      'class' => array('input-nuoc-ngoai'), 
    ),
  );

  $form['group_basic_info_ht']['hut_thuoc'] = array(
    '#type' => 'radios',
    '#title' => t('Có hút thuốc không ?'),
    '#options' => array(
      '1' => t('Có'),
      '0' => t('Không'),
    ),
  );

  $form['group_basic_info_ht']['uong_ruou'] = array(
    '#type' => 'radios',
    '#title' => t('Có uống rượu không ?'),
    '#options' => array(
      '1' => t('Có'),
      '0' => t('Không'),
    ),
  );

  $form['group_basic_info_cv'] = array(
    '#type' => 'container',
    '#attributes' => array(
      'class' => array('group-info-row-3'), 
    ),
  );

  $form['group_basic_info_cv']['cv_hien_tai'] = array(
    '#type' => 'textfield',
    '#title' => t('Công việc hiện tại là gì?'),
    '#required' => TRUE,
    '#attributes' => array('placeholder' => t('Công việc hiện tại')),
  );

  $form['group_basic_info_cv']['muc_luong'] = array(
    '#type' => 'textfield',
    '#title' => t('Mức lương hiện tại bao nhiêu'),
    '#required' => TRUE,
    '#attributes' => array('placeholder' => t('Lương hiện tại')),
  );

    $form['group_basic_info_cv']['muc_luong_mong_muon'] = array(
    '#type' => 'textfield',
    '#title' => t('Mức lương mong muốn bao nhiêu'),
    '#required' => TRUE,
    '#attributes' => array('placeholder' => t('Lương mong muốn')),
  );

  $form['nganh_mong_muon'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Ngành bạn mong muốn học'),
    '#options' => array(
      'Ngành điều khiển tàu biển' => t('Ngành điều khiển tàu biển'),
      'Ngành máy tàu biển' => t('Ngành máy tàu biển'),
      'Ngành điện tàu biển' => t('Ngành điện tàu biển'),
      'Ngành chế biến món ăn' => t('Ngành chế biến món ăn'),
    ),
  );
 
    $form['file_cccd'] = array(
    '#type' => 'managed_file',
    '#title' => t('File đính kèm ảnh căn cước công dân'),
    '#upload_location' => 'public://cccd_uploads/', 
    '#attributes' => array('class' => array('customer-drop')),
    '#upload_validators' => array(
      'file_validate_extensions' => array('gif png jpg jpeg pdf docx'), // Các định dạng cho phép
      'file_validate_size' => array(5 * 1024 * 1024), // Giới hạn 5MB như trong ảnh
    ),
  );

    // 1. Phần thông tin Hotline (Dùng Markup để viết HTML trực tiếp)
  $form['hotline_info'] = array(
    '#markup' => '
      <div class="hotline-container">
  <p>Hotline tư vấn, đào tạo, tuyển dụng lao động</p>
  <div class="hotline-contacts">
    <div class="hotline-contact">
      <a href="tel:0366.893.485">0366.893.485</a>
      <span>- Ms Thu Trang (Zalo)</span>
    </div>
    <div class="hotline-contact">
      <a href="tel:090.151.8819">090.151.8819</a>
      <span>- Ms Thắm (Zalo)</span>
    </div>
    <div class="hotline-contact">
      <a href="tel:0904.162.189">0904.162.189</a>
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
    '#value' => t('Gửi thông tin'),
    '#submit' => array('pacific_isea_contact_customer_form_submit'),
    '#attributes' => array('class' => array('btn-gui-ho-so')),
  );
 
$form['#attached']['library'][] = 'pacific_isea_contact/file-upload-lib';

  return $form;
}

function pacific_isea_contact_customer_form_submit($form, &$form_state) {
  $v = $form_state['values'];
  $tuoi_db = '';
if (!empty($v['tuoi'])) {
    // Chuyển từ dd/mm/yyyy sang yyyy-mm-dd
    $date_obj = DateTime::createFromFormat('d/m/Y', $v['tuoi']);
    $tuoi_db = $date_obj ? $date_obj->format('Y-m-d') : '';
}
  $nganh_mong_muon = !empty($v['nganh_mong_muon']) ? implode(', ', array_filter($v['nganh_mong_muon'])) : '';
  $ngon_ngu = !empty($v['ngon_ngu']) ? implode(', ', array_filter($v['ngon_ngu'])) : '';
  $fid_cccd = !empty($v['file_cccd']) ? $v['file_cccd'] : 0;
  // Lưu vào Database
  try{
      db_insert('isea_tuyen_dung')
    ->fields(array(
      'ho_ten' => $v['ho_ten'],
      'tuoi'   => $tuoi_db,
      'sdt' => $v['sdt'],
      'hon_nhan' => $v['tinh_trang_hon_nhan'],
      'so_con' => $v['so_con'],
      'que_quan' => $v['que_quan'],
      'HoTenNguoiThan' => $v['HoTenNguoiThan'],
      'MoiQuanHeNguoiThan' => $v['MoiQuanHeNguoiThan'],
      'SDTNguoiThan' => $v['SDTNguoiThan'],
      'hoc_van' => $v['hoc_van'],
      'ngon_ngu' => $ngon_ngu, 
      'ld_nuoc_ngoai' => $v['ld_nuoc_ngoai'],
      'ten_nuoc_chi_tiet' => $v['ten_nuoc_chi_tiet'],
      'hut_thuoc' => $v['hut_thuoc'],
      'uong_ruou' => $v['uong_ruou'],
      'cv_hien_tai' => $v['cv_hien_tai'],
      'luong_hien_tai' => $v['muc_luong'],
      'muc_luong_mong_muon' => $v['muc_luong_mong_muon'],
      'nganh_mong_muon' => $nganh_mong_muon,
       'file_cccd' => $fid_cccd,
      'created' => REQUEST_TIME,
    ))
    ->execute();

 if ($fid_cccd > 0) {
  $file = file_load($fid_cccd);
  if ($file) {
    $file->status = FILE_STATUS_PERMANENT;
    file_save($file);
    file_usage_add($file, 'pacific_isea_contact', 'tuyen_dung', $fid_cccd);
    $fields['file_cccd'] = $fid_cccd;
  }
}

  drupal_set_message('Hồ sơ đã được gửi thành công!');
  $_SESSION['isea_show_popup'] = TRUE;
  } catch (Exception $e) {
    drupal_set_message($e->getMessage(), 'error'); 
  }
}

/**
 * 3. Trang hiển thị danh sách trong Admin
 */
function pacific_isea_contact_admin_list() {
  $header = array('ID', 'Họ tên','Bao nhiêu tuổi','Số điện thoại','Tình trạng hôn nhân','Số con','Quê quán',
  'Họ tên người bảo lãnh','Mối quan hệ người bảo lãnh','Số điện thoại người bảo lãnh',
  'Trình độ học vấn','Bạn biết những ngôn ngữ nào?','Từng đi lao động ở nước ngoài chưa?','Nước nào?',
  'Có hút thuốc không ?','Có uống rượu không','Công việc hiện tại là gì','Mức lương hiện tại','Mức lương mong muốn',
  'Ngành bạn mong muốn học','File CCCD','Ngày gửi');
  $rows = array();

  $result = db_select('isea_tuyen_dung', 't')
    ->fields('t')
    ->orderBy('created', 'DESC')
    ->execute();

    foreach ($result as $record) {
      $file_display = t('Không có file'); 
  if (!empty($record->file_cccd)) {
    $file_obj = file_load($record->file_cccd);
    if ($file_obj) {
      // Tạo URL đầy đủ đến file
      $url = file_create_url($file_obj->uri);
      // Tạo link HTML: <a href="..." target="_blank">Xem ảnh/file</a>
      $file_display = l(t('Xem ảnh/file'), $url, array(
        'attributes' => array('target' => '_blank', 'title' => $file_obj->filename)
      ));
    }
  }
$hien_thi_tuoi = '';
if (!empty($record->tuoi) && $record->tuoi != '0000-00-00') {
    $hien_thi_tuoi = date('d/m/Y', strtotime($record->tuoi));
}
    $rows[] = array(
      $record->id,
      check_plain($record->ho_ten),
      $hien_thi_tuoi,
      check_plain($record->sdt),
      check_plain($record->hon_nhan),
      check_plain($record->so_con),
      check_plain($record->que_quan),
      check_plain($record->HoTenNguoiThan),
      check_plain($record->MoiQuanHeNguoiThan),
      check_plain($record->SDTNguoiThan),
      check_plain($record->hoc_van),
      check_plain($record->ngon_ngu),
      $record->ld_nuoc_ngoai,
      check_plain($record->ten_nuoc_chi_tiet),
      $record->hut_thuoc,
      $record->uong_ruou,
      check_plain($record->cv_hien_tai),
      check_plain($record->luong_hien_tai),
      check_plain($record->muc_luong_mong_muon),
      check_plain($record->nganh_mong_muon),
      $file_display,
      format_date($record->created, 'short'),
    );
  }


  $link_export = l('📥 Xuất file Excel (CSV)', 'admin/gui-ho-so/export', array('attributes' => array('style' => 'font-weight:bold; color:green;')));
  return $link_export . theme('table', array('header' => $header, 'rows' => $rows));
}


/**
 * 4. Hàm xuất CSV để mở bằng Excel
 */
function pacific_isea_contact_export_csv() {
  header('Content-Type: text/csv; charset=utf-8');
  header('Content-Disposition: attachment; filename=ds-tuyen-dung.csv');
  $fp = fopen('php://output', 'w');
  fprintf($fp, chr(0xEF).chr(0xBB).chr(0xBF)); 
  
  fputcsv($fp, array('ID', 'Họ tên','Bao nhiêu tuổi','Số điện thoại','Tình trạng hôn nhân','Số con','Quê quán',
  'Họ tên người bảo lãnh','Mối quan hệ người bảo lãnh','Số điện thoại người bảo lãnh',
  'Trình độ học vấn','Bạn biết những ngôn ngữ nào?','Từng đi lao động ở nước ngoài chưa?','Nước nào?',
  'Có hút thuốc không ?','Có uống rượu không','Công việc hiện tại là gì','Mức lương hiện tại','Mức lương mong muốn',
  'Ngành bạn mong muốn học','File CCCD','Ngày gửi'));
  $data = db_select('isea_tuyen_dung', 't')->fields('t')->execute();
  foreach ($data as $r) {
      $file_url = ''; 
  if (!empty($r->file_cccd)) {
    $file_obj = file_load($r->file_cccd); 
    if ($file_obj) {
      $file_url = file_create_url($file_obj->uri);
    }
  }
  $csv_date = '';
if (!empty($r->tuoi) && $r->tuoi != '0000-00-00') {
    $csv_date = date('d/m/Y', strtotime($r->tuoi));
}
    fputcsv($fp, array($r->id, $r->ho_ten,  
     $csv_date,
    $r->sdt, $r->hon_nhan, $r->so_con,
    $r->que_quan, $r->HoTenNguoiThan,
    $r->MoiQuanHeNguoiThan,
    $r->SDTNguoiThan,
    $r->hoc_van,
    $r->ngon_ngu,
    $r->ld_nuoc_ngoai,
    $r->ten_nuoc_chi_tiet,
    $r-> hut_thuoc,
    $r->uong_ruou,
    $r->cv_hien_tai,
    $r->luong_hien_tai,
    $r->muc_luong_mong_muon,
    $r->nganh_mong_muon,
    $file_url,
    date('d/m/Y', $r->created)));
  }
  fclose($fp);
}
