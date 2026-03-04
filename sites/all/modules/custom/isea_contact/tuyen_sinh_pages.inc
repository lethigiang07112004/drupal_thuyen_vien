<?php
function tuyen_sinh_callback() {
  $form = drupal_get_form('isea_contact_tt_form'); 
  $form_output = drupal_render($form);

  $logo_path = base_path() . drupal_get_path('theme', 'tuyen_dung') . '/images/images1.jpg';

  $output = '<!DOCTYPE html>
  <html>
  <head>
    <title>Liên hệ PACIFIC</title>
    <meta charset="utf-8">
    <link rel="stylesheet" href="' . drupal_get_path('module', 'isea_contact') . '/css/style.css">
    <script src="/sites/all/modules/custom/isea_contact/js/file_upload.js"></script>
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
function isea_contact_tt_form($form, &$form_state) { 
   $form['group_basic_info'] = array(
    '#type' => 'container',
    '#attributes' => array(
      'class' => array('group-info-row'), 
    ),
  );

  $form['group_basic_info']['chuc_danh'] = array(
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
  );

  $form['group_basic_info']['ho_ten'] = array(
    '#type' => 'textfield',
    '#title' => t('Họ và tên'),
    '#required' => TRUE,
    '#attributes' => array('placeholder' => t('Nhập họ tên')),
  );

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

  $form['group_basic_info_ttc'] = array(
    '#type' => 'container',
    '#attributes' => array(
      'class' => array('group-info-row-5'), 
    ),
  );
  $form['group_basic_info_ttc']['chieu_cao'] = array(
    '#type' => 'textfield',
    '#title' => t('Chiều cao (cm)'),
    '#required' => TRUE,
    '#attributes' => array('placeholder' => t('170')),
  );

  $form['group_basic_info_ttc']['can_nang'] = array(
    '#type' => 'textfield',
    '#title' => t('Cân nặng (kg)'),
    '#required' => TRUE,
    '#attributes' => array('placeholder' => t('65')),
  );

  $form['group_basic_info_ttc']['size_giay'] = array(
    '#type' => 'select',
    '#title' => t('Size giày'),
     '#options' => array(
      '' => t('- Chọn tình trạng -'),
      '36' => t('36'),
      '37' => t('37'),
      '38' => t('38'),
      '39' => t('39'),
      '40' => t('40'),
      '41' => t('41'),
      '42' => t('42'),
      '43' => t('43'),
      '44' => t('44'),
      '45' => t('45'),
    ),
    '#required' => TRUE,
  );

  $form['group_basic_info_ttc']['co_quan_ao'] = array(
    '#type' => 'select',
    '#title' => t('Cỡ quần áo'),
     '#options' => array(
      '' => t('- Chọn tình trạng -'),
      'XS' => t('XS'),
      'S' => t('S'),
      'M' => t('M'),
      'L' => t('L'),
      'XL' => t('XL'),
      'XXL' => t('XXL'),
      'XXXL' => t('XXXL'),
    ),
    '#required' => TRUE,
  );


   $form['que_quan'] = array(
    '#type' => 'textfield',
    '#title' => t('Địa chỉ'),
    '#required' => TRUE,
    '#attributes' => array('placeholder' => t('Nhập thông tin')),
  );
  $form['group_basic_info_se'] = array(
    '#type' => 'container',
    '#attributes' => array(
      'class' => array('group-info-row-4'), 
    ),
  );
  $form['group_basic_info_se']['sdt'] = array(
    '#type' => 'textfield',
    '#title' => t('Số điện thoại'),
    '#required' => TRUE,
    '#attributes' => array('placeholder' => t('Số điện thoại')),
  );
  $form['group_basic_info_se']['mcft'] = array(
    '#type' => 'textfield',
    '#title' => t('Microsoft team'),
    '#required' => TRUE,
    '#attributes' => array('placeholder' => t('Microsoft team')),
  );
  $form['group_basic_info_se']['email'] = array(
    '#type' => 'textfield',
    '#title' => t('Email'),
    '#required' => TRUE,
    '#attributes' => array('placeholder' => t('Email')),
  );
  $form['group_basic_info_nv'] = array(
    '#type' => 'container',
    '#attributes' => array(
      'class' => array('group-info-row-6'), 
    ),
  );
$form['group_basic_info_nv']['muc_luong'] = array(
    '#type' => 'textfield',
    '#title' => t('Mức lương thấp nhất có thể chấp nhận'),
    '#required' => TRUE,
    '#attributes' => array('placeholder' => t('Mức lương thấp nhất có thể chấp nhận')),
  );
$form['group_basic_info_nv']['mong_muon'] = array(
    '#type' => 'textfield',
    '#title' => t('Nguyện vọng, mong muốn khác'),
    '#required' => TRUE,
    '#attributes' => array('placeholder' => t('Nguyện vọng, mong muốn khác')),
  );
  $form['group_basic_info_nt'] = array(
    '#type' => 'container',
    '#attributes' => array(
      'class' => array('group-info-row-5'), 
    ),
  );

  $form['group_basic_info_nt']['HoTenNguoiThan'] = array(
    '#type' => 'textfield',
    '#title' => t('Họ tên người bảo lãnh'),
    '#required' => TRUE,
    '#attributes' => array('placeholder' => t('Họ tên người bảo lãnh')),
  );

  $form['group_basic_info_nt']['MoiQuanHeNguoiThan'] = array(
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

  $form['group_basic_info_nt']['nam_sinh'] = array(
    '#type' => 'textfield',
    '#title' => t('Năm sinh người bảo lãnh'),
    '#required' => TRUE,
    '#attributes' => array('placeholder' => t('Nhập năm sinh')),
  );


   $form['group_basic_info_nt']['SDTNguoiThan'] = array(
    '#type' => 'textfield',
    '#title' => t('Số điện thoại người bảo lãnh'),
    '#required' => TRUE,
    '#attributes' => array('placeholder' => t('SĐT người bảo lãnh')),
  );
$form['group_basic_info_ht'] = array(
    '#type' => 'container',
    '#attributes' => array(
      'class' => array('group-info-row-2'), 
    ),
  );

  $form['group_basic_info_ht']['hoc_van'] = array(
    '#type' => 'select',
    '#title' => t('Học trường Hàng Hải nào'),
     '#options' => array(
      '' => t('- Chọn thông tin -'),
      'Đại Học Hàng Hải VN' => t('Đại Học Hàng Hải VN'),
      'ĐHGTVT Hồ Chí Minh' => t('ĐHGTVT Hồ Chí Minh'),
      'Cao Đẳng Hàng Hải 1' => t('Cao Đẳng Hàng Hải 1'),
      'Cao Đẳng Hàng Hải 2' => t('Cao Đẳng Hàng Hải 2'),
      'Cao Đẳng Nghề Bách Nghệ' => t('Cao Đẳng Nghề Bách Nghệ'),
      'Cao Đẳng Nghề Duyên Dải' => t('Cao Đẳng Nghề Duyên Dải'),
    ),
    '#required' => TRUE,
  );
  $form['group_basic_info_ht']['tot_nghiep'] = array(
    '#type' => 'textfield',
    '#title' => t('Thời gian tốt nghiệp'),
    '#required' => TRUE,
    '#attributes' => array('placeholder' => t('2000-2004')),
  );
 

  $form['group_basic_info_ht']['ngon_ngu'] = array(
    '#type' => 'textfield',
    '#title' => t('Bạn biết những ngôn ngữ nào?'),
    '#required' => TRUE,
    '#attributes' => array('placeholder' => t('Nhập ngôn ngữ')),
  );
 
  $form['group_basic_info_gt'] = array(
    '#type' => 'container',
    '#attributes' => array(
      'class' => array('group-info-row-5'), 
    ),
  );
  $form['group_basic_info_gt']['group_basic_info_ld'] = array(
    '#type' => 'container',
    '#attributes' => array(
      'class' => array('group-info-row-1'), 
    ),
  );

  $form['group_basic_info_gt']['group_basic_info_ld']['ld_nuoc_ngoai'] = array(
    '#type' => 'radios',
    '#title' => t('Từng đi lao động ở nước ngoài chưa? / Nước nào?'),
    '#options' => array(
      '1' => t('Có'),
      '0' => t('Không'),
    ),
    '#required' => TRUE, 
  );

  $form['group_basic_info_gt']['group_basic_info_ld']['ten_nuoc_chi_tiet'] = array(
    '#type' => 'textfield',
    '#attributes' => array(
      'placeholder' => t('Nhập tên nước đã lao động'),
      'class' => array('input-nuoc-ngoai'), 
    ),
  );

  $form['group_basic_info_gt']['group_basic_info_giay_to'] = array(
    '#type' => 'container',
    '#attributes' => array(
      'class' => array('group-info-row-1'), 
    ),
  );

  $form['group_basic_info_gt']['group_basic_info_giay_to']['tt_giay_to'] = array(
    '#type' => 'radios',
    '#title' => t('Tình trạng giấy tờ'),
    '#options' => array(
      'Cầm tay' => t('Cầm tay'),
      'Đang để tại văn phòng cty khác' => t('Đang để tại văn phòng cty khác'),
      'Lý do khác' => t('Lý do khác'),
    ),
    '#required' => TRUE, 
  );

  $form['group_basic_info_gt']['group_basic_info_giay_to']['ly_do'] = array(
    '#type' => 'textfield',
    '#attributes' => array(
      'placeholder' => t('Nhập tên lý do'),
      'class' => array('input-nuoc-ngoai'), 
    ),
  );

  $form['group_basic_info_gt']['hut_thuoc'] = array(
    '#type' => 'radios',
    '#title' => t('Có hút thuốc không ?'),
    '#options' => array(
      '1' => t('Có'),
      '0' => t('Không'),
    ),
  );

  $form['group_basic_info_gt']['uong_ruou'] = array(
    '#type' => 'radios',
    '#title' => t('Có uống rượu không ?'),
    '#options' => array(
      '1' => t('Có'),
      '0' => t('Không'),
    ),
  );

  $form['kinh_nghiem'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Có kinh nghiệm vào các nước sau chưa'),
    '#options' => array(
      'Úc' => t('Úc'),
      'Mỹ' => t('Mỹ'),
      'Canada' => t('Canada'),
      'New Zealand' => t('New Zealand'),
      'Hàn Quốc' => t('Hàn Quốc'),
      'Châu Âu' => t('Châu Âu'),
    ),
  );

  $form['mix_tv'] = array(
    '#type' => 'textfield',
    '#title' => t('Đã đi mix với thuyền viên nước nào rồi ? '),
    '#required' => TRUE,
    '#attributes' => array('placeholder' => t('Nhập thông tin')),
  );

  $form['group_basic_info_cv'] = array(
    '#type' => 'container',
    '#attributes' => array(
      'class' => array('group-info-row-7'), 
    ),
  );

  $form['group_basic_info_cv']['loai_tau'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Từng đi kinh nghiệm loại tàu nào rồi?'),
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
      'Tàu General Cargo' => t('Tàu General Cargo'),
    ),
  );
 $form['group_basic_info_cv']['ten_tau'] = array(
    '#type' => 'textfield',
    '#attributes' => array('placeholder' => t('Nhập tàu')),
  );
 
$form['group_basic_info_tb'] = array(
    '#type' => 'container',
    '#attributes' => array(
      'class' => array('group-info-row-7'), 
    ),
  );

  $form['group_basic_info_tb']['hai_do'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Có kinh nghiệm loại Hải Đồ điện tử nào rồi'),
    '#options' => array(
      'Furuno' => t('Furuno'),
      'Tàu JRC' => t('JRC'),
      'Tokyo Keiki' => t('Tokyo Keiki'),
    ),
  );
 $form['group_basic_info_tb']['ten_thiet_bi'] = array(
    '#type' => 'textfield',
    '#attributes' => array('placeholder' => t('Nhập thiết bị khác')),
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
  <p>Hotline tư vấn, đào tạo, tuyển dụng thuyền viên</p>
  <div class="hotline-contacts">
    <div class="hotline-contact">
      <a href="tel:0867560587">0867.560.587</a>
      <span>- Ms Thu Hiền (Zalo)</span>
    </div>
    <div class="hotline-contact">
      <a href="tel:0862758586">0862.758.586</a>
      <span>- Ms Trần Hiền (Zalo)</span>
    </div>
    <div class="hotline-contact">
      <a href="tel:0337490287">0337490287</a>
      <span>- Ms Thảo (Zalo)</span>
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
    '#value' => t('Gửi hồ sơ'),
    '#submit' => array('isea_contact_tt_form_submit'),
    '#attributes' => array('class' => array('btn-gui-ho-so')),
  );
 
$form['#attached']['library'][] = 'isea_contact/file-upload-lib';

  return $form;
}

/**
 * 4. Hàm xử lý submit 
 */
function isea_contact_tt_form_submit($form, &$form_state) {
  $v = $form_state['values'];
  $tuoi_db = '';
if (!empty($v['tuoi'])) {
    // Chuyển từ dd/mm/yyyy sang yyyy-mm-dd
    $date_obj = DateTime::createFromFormat('d/m/Y', $v['tuoi']);
    $tuoi_db = $date_obj ? $date_obj->format('Y-m-d') : '';
} 
  $kinh_nghiem = !empty($v['kinh_nghiem']) ? implode(', ', array_filter($v['kinh_nghiem'])) : '';
  $loai_tau = !empty($v['loai_tau']) ? implode(', ', array_filter($v['loai_tau'])) : '';
  $hai_do = !empty($v['hai_do']) ? implode(', ', array_filter($v['hai_do'])) : '';
  
  $fid_cccd = !empty($v['file_cccd']) ? $v['file_cccd'] : 0;
  // Lưu vào Database
  try{
      db_insert('isea_thuyen_vien')
    ->fields(array(
      'chuc_danh' => $v['chuc_danh'],
      'ho_ten' => $v['ho_ten'],
      'tuoi'   => $tuoi_db,
      'hon_nhan' => $v['tinh_trang_hon_nhan'],
      'so_con' => $v['so_con'],
      'chieu_cao' => $v['chieu_cao'],
      'can_nang' => $v['can_nang'],
      'size_giay' => $v['size_giay'],
      'co_quan_ao' => $v['co_quan_ao'],
      'que_quan' => $v['que_quan'],
      'sdt' => $v['sdt'],
      'mcft' => $v['mcft'],
      'email' => $v['email'],
      'muc_luong' => $v['muc_luong'],
      'mong_muon' => $v['mong_muon'],
      'HoTenNguoiThan' => $v['HoTenNguoiThan'],
      'MoiQuanHeNguoiThan' => $v['MoiQuanHeNguoiThan'],
      'nam_sinh' => $v['nam_sinh'],
      'SDTNguoiThan' => $v['SDTNguoiThan'],
      'hoc_van' => $v['hoc_van'],
      'tot_nghiep' => $v['tot_nghiep'],
      'ngon_ngu' => $v['ngon_ngu'], 
      'ld_nuoc_ngoai' => $v['ld_nuoc_ngoai'],
      'ten_nuoc_chi_tiet' => $v['ten_nuoc_chi_tiet'],
      'tt_giay_to' => $v['tt_giay_to'],
      'ly_do' => $v['ly_do'],
      'hut_thuoc' => $v['hut_thuoc'],
      'uong_ruou' => $v['uong_ruou'],
      'kinh_nghiem' => $kinh_nghiem,
      'mix_tv' => $v['mix_tv'],
      'loai_tau' => $loai_tau,
      'ten_tau' => $v['ten_tau'],
      'hai_do' => $hai_do,
      'ten_thiet_bi' => $v['ten_thiet_bi'],
       'file_cccd' => $fid_cccd,
      'created' => REQUEST_TIME,
    ))
    ->execute();

 if ($fid_cccd > 0) {
  $file = file_load($fid_cccd);
  if ($file) {
    $file->status = FILE_STATUS_PERMANENT;
    file_save($file);
    file_usage_add($file, 'isea_contact', 'tuyen_dung', $fid_cccd);
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
function isea_contact_admin_tt_list() {
  $header = array('ID', 'Chức danh','Họ tên','Bao nhiêu tuổi','Tình trạng hôn nhân','Số con',
  'Chiều cao','Cân nặng','Size-giày','Cỡ quần áo','Địa chỉ','Số điện thoại','Microsoft team','Email',
  'Mức lương thấp nhất có thể chấp nhận','Nguyện vọng, mong muốn khác',
  'Họ tên người bảo lãnh','Mối quan hệ người bảo lãnh','Năm sinh người bảo lãnh','Số điện thoại người bảo lãnh',
  'Học trường Hàng Hải nào ','Thời gian tốt nghiệp ','Bạn biết những ngôn ngữ nào?','Từng đi lao động ở nước ngoài chưa?','Nước nào?',
  'Tình trạng giấy tờ','Lí do khác',
  'Có hút thuốc không ?','Có uống rượu không','Có kinh nghiệm vào các nước sau chưa ','Đã đi mix với thuyền viên nước nào rồi ?','Từng đi kinh nghiệm loại tàu nào rồi?',
  'Tên tàu khác','Có kinh nghiệm loại Hải Đồ điện tử nào rồi','Nhập tên thiết bị khác','File CCCD','Ngày gửi');
  $rows = array();

  $result = db_select('isea_thuyen_vien', 't')
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
      check_plain($record->chuc_danh),
      check_plain($record->ho_ten),
      $hien_thi_tuoi,
      check_plain($record->hon_nhan),
      check_plain($record->so_con),
      check_plain($record->chieu_cao),
      check_plain($record->can_nang),
      check_plain($record->size_giay),
      check_plain($record->co_quan_ao),
      check_plain($record->que_quan),
      check_plain($record->sdt),
      check_plain($record->mcft),
      check_plain($record->email),
      check_plain($record->muc_luong),
      check_plain($record->mong_muon),
      check_plain($record->HoTenNguoiThan),
      check_plain($record->MoiQuanHeNguoiThan),
      check_plain($record->nam_sinh),
      check_plain($record->SDTNguoiThan),
      check_plain($record->hoc_van),
      check_plain($record->tot_nghiep),
      check_plain($record->ngon_ngu),
      $record->ld_nuoc_ngoai,
      check_plain($record->ten_nuoc_chi_tiet),
      $record->tt_giay_to,
      check_plain($record->ly_do),
      $record->hut_thuoc,
      $record->uong_ruou,
      check_plain($record->kinh_nghiem),
      check_plain($record->mix_tv),
      check_plain($record->loai_tau),
      check_plain($record->ten_tau),
      check_plain($record->hai_do),
      check_plain($record->ten_thiet_bi),
      $file_display,
      format_date($record->created, 'short'),
    );
  }


  $link_export = l('📥 Xuất file Excel (CSV)', 'admin/tuyen-sinh/export', array('attributes' => array('style' => 'font-weight:bold; color:green;')));
  return $link_export . theme('table', array('header' => $header, 'rows' => $rows));
}


/**
 * 4. Hàm xuất CSV để mở bằng Excel
 */
function isea_contact_tt_export_csv() {
  header('Content-Type: text/csv; charset=utf-8');
  header('Content-Disposition: attachment; filename=ds-thuyen_vien.csv');
  $fp = fopen('php://output', 'w');
  fprintf($fp, chr(0xEF).chr(0xBB).chr(0xBF)); 
  
  fputcsv($fp, array('ID', 'Chức danh','Họ tên','Bao nhiêu tuổi','Tình trạng hôn nhân','Số con',
  'Chiều cao','Cân nặng','Size-giày','Cỡ quần áo','Địa chỉ','Số điện thoại','Microsoft team','Email',
  'Mức lương thấp nhất có thể chấp nhận','Nguyện vọng, mong muốn khác',
  'Họ tên người bảo lãnh','Mối quan hệ người bảo lãnh','Năm sinh người bảo lãnh','Số điện thoại người bảo lãnh',
  'Học trường Hàng Hải nào ','Thời gian tốt nghiệp ','Bạn biết những ngôn ngữ nào?','Từng đi lao động ở nước ngoài chưa?','Nước nào?',
  'Tình trạng giấy tờ','Lí do khác',
  'Có hút thuốc không ?','Có uống rượu không','Có kinh nghiệm vào các nước sau chưa ','Đã đi mix với thuyền viên nước nào rồi ?','Từng đi kinh nghiệm loại tàu nào rồi?',
  'Tên tàu khác','Có kinh nghiệm loại Hải Đồ điện tử nào rồi','Nhập tên thiết bị khác','File CCCD','Ngày gửi'));
  $data = db_select('isea_thuyen_vien', 't')->fields('t')->execute();
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
    fputcsv($fp, array(
    $r->id,$r->chuc_danh, 
    $r->ho_ten,  
    $csv_date,
    $r->hon_nhan, $r->so_con,
    $r->chieu_cao, $r->can_nang, $r->size_giay,$r->co_quan_ao, 
    $r->que_quan,$r->sdt,$r->mcft,$r->email, 
    $r->muc_luong,$r->mong_muon,
    $r->HoTenNguoiThan,
    $r->MoiQuanHeNguoiThan,$r->nam_sinh,
    $r->SDTNguoiThan,
    $r->hoc_van,$r->tot_nghiep,
    $r->ngon_ngu,
    $r->ld_nuoc_ngoai,
    $r->ten_nuoc_chi_tiet,
    $r->tt_giay_to,
    $r->ly_do,
    $r-> hut_thuoc,
    $r->uong_ruou,
    $r->kinh_nghiem,
    $r->mix_tv,
    $r->loai_tau,
    $r->ten_tau,
    $r->hai_do,
    $r->ten_thiet_bi,
    $file_url,
    date('d/m/Y', $r->created)));
  }
  fclose($fp);
}


