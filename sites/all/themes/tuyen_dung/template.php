<?php
  function getMainMenu()
  {
    $mainMenu = menu_tree_all_data('main-menu');
    $str = "";
    foreach ($mainMenu as $item) {
         //dpm($item);
      if ($item['link']['hidden'] == 0) {
        // Nếu không có menu con
        if (count($item['below']) == 0) {
          $str .= '<li>';
          $str .= l(
            $item['link']['link_title'],
            $item['link']['link_path'],
            array(
              'attributes' => array(
                'class'=>array('nav-link'),
                'title' => $item['link']['link_title']
              ),
              'html' => true
            )

          );
          $str .='<span class="d-xl-block d-lg-block d-none">';
          $str .= $item['link']['localized_options']['attributes']['title'];
          $str .='</span>';
        } else {
          $str .= '<li>';
          $str .= l(
            $item['link']['link_title'],
            $item['link']['link_path'],
            array(
              'attributes' => array(
                'class'=>array('nav-link dropdown-toggle'),
                'title' => $item['link']['link_title']
              ),
              'html' => true
            )
          );
          $str .='<span class="d-xl-block d-lg-block d-none">';
          $str .= $item['link']['localized_options']['attributes']['title'];
          $str .='</span>';
        }

        // nếu có menu con
        if (count($item['below']) > 0) {
          $str .= '<ul class="dropdown-nav">';
          foreach ($item['below'] as $subItem) {
            if ($subItem['link']['hidden'] == 0){
              if (count($subItem['below']) == 0){
                $str .="<li>" . l(
                    '<i class="icon-feather-chevron-right"></i>'.$subItem['link']['link_title'],
                    $subItem['link']['link_path'],
                    array(
                      'attributes' => array(
                        'class'=>array('nav-link'),
                        'title' => $item['link']['link_title']
                      ),
                      'html' => true
                    )
                  );
              }else{
                $str .="<li>" . l(
                    '<i class="icon-feather-chevron-right"></i>'.$subItem['link']['link_title'],
                    $subItem['link']['link_path'],
                    array(
                      'attributes' => array(
                        'class'=>array('nav-link sub-link'),
                        'title' => $item['link']['link_title']
                      ),
                      'html' => true
                    )
                  );
                $str .= '<ul class="dropdown-nav">';
                foreach ($subItem['below'] as $childItem){
                  if ($childItem['link']['hidden'] == 0){
                    $str .="<li>" . l(
                        '<i class="icon-feather-chevron-right"></i>'.$childItem['link']['link_title'],
                        $childItem['link']['link_path'],
                        array(
                          'attributes' => array(
                            'class'=>array('nav-link'),
                            'title' => $childItem['link']['link_title']
                          ),
                          'html' => true
                        )
                      );
                    $str .= '</li>';
                  }
                }
                $str .= '</ul>';
              }
              $str .= '</li>';
            }

          }
          $str .= '</ul>';
        }
        $str .= '</li>';

      }

    }

    return '<ul id="responsive">' . $str . '</ul>';
  }
  function getMainMenuDanhMuc()
  {
    $mainMenu = menu_tree_all_data('menu-danh-muc');
    $str = "";
    foreach ($mainMenu as $item) {
      //        dpm($item);
      if ($item['link']['hidden'] == 0) {
        // Nếu không có menu con
        if (count($item['below']) == 0) {
          $str .= '<li>';
          $str .= l(
            '<i class="icon-feather-chevrons-right"></i>'.$item['link']['link_title'],
            $item['link']['link_path'],
            array(
              'attributes' => array(
                'class'=>array('nav-link'),
                'title' => $item['link']['link_title']
              ),
              'html' => true
            )
          );
        } else {
          $str .= '<li>';
          $str .= l(
            '<i class="icon-feather-chevrons-right"></i>'.$item['link']['link_title'],
            $item['link']['link_path'],
            array(
              'attributes' => array(
                'class'=>array('nav-link dropdown-toggle'),
                'title' => $item['link']['link_title']
              ),
              'html' => true
            )
          );
        }

        // nếu có menu con
        if (count($item['below']) > 0) {
          $str .= '<ul class="dropdown-nav">';
          foreach ($item['below'] as $subItem) {
            if ($subItem['link']['hidden'] == 0)
              $str .= "<li>" . l(
                '<i class="icon-feather-chevron-right"></i>'.$subItem['link']['link_title'],
                $subItem['link']['link_path'],
                array(
                  'attributes' => array(
                    'class'=>array('nav-link'),
                    'title' => $item['link']['link_title']
                  ),
                  'html' => true
                )
              ) . "</li>";
          }
          $str .= '</ul>';
        }
        $str .= '</li>';
      }
    }

    return '<ul class="mt-mb-30">' . $str . '</ul>';
  }
  function menufooter()
  {
    $mainMenu = menu_tree_all_data('main-menu');
    $str = "";
    $run=0;
    foreach ($mainMenu as $item) {
      //        dpm($item);
      if ($item['link']['hidden'] == 0) {
        if($run>=1)
        {
          $str .= '<li class="menu_f">';
          $str .= l(
            '<i class="icon-feather-chevron-right"></i> <span>'.$item['link']['link_title'].'</span>',
            $item['link']['link_path'],
            array(
              'attributes' => array(
                'class'=>array('nav-link'),
                'title' => $item['link']['link_title'],
              ),
              'html' => true
            )
          );
          $str .= '</li>';
        }
        $run++;
      }
    }

    return '<ul>' . $str . '</ul>';
  }
  function getnodecontent($nid)
  {
    if(isset(node_load($nid)->field_mo_ta_slider['und'][0]['value']))
    {
      return node_load($nid)->field_mo_ta_slider['und'][0]['value'];
    }
    return '';
  }
  function tuyen_dung_form_webform_client_form_1_alter(&$form, &$form_state, $form_id)
  {
    $form['actions']['submit']['#attributes']['class'] = array('d-none');
    $form['actions']['submit']['#prefix']=t('<button type="submit" class="submit button" id="submit"><i class="icon-feather-send mr-15"></i>SEND</button>');
  }
  function getinfo_slider()
  {
    $str='
      <div class="row">
          <div class="col-md-12">
            <ul class="intro-stats margin-top-45 hide-under-992px">
              <li><i class="icon-material-outline-business-center"></i> <sub class="counter_item"><strong class="counter">18,955</strong> <span>Công việc</span></sub> </li>
              <li><i class="icon-line-awesome-user"></i> <sub class="counter_item"><strong class="counter">11,088</strong> <span>Nhân lực</span></sub> </li>
              <li><i class="icon-feather-user-plus"></i> <sub class="counter_item"><strong class="counter">10,758</strong> <span>Cần tuyển</span></sub> </li>
            </ul>
          </div>
        </div>
      '
    ;
    return $str;
  }
  function form_search_side()
  {
    $val='';
    if(isset($_GET['title']))
    {
      $val=$_GET['title'];
    }
    $str='<form action="/tim-kiem" method="get">
            <div class="utf-input-with-icon">
              <input type="text" name="title" placeholder="Tìm kiếm..." value="'.$val.'">
              <button type="submit" class="button_search"><i class="icon-material-outline-search"></i></button>
            </div>
          </form>';
    return $str;
  }
  function form_dang_ky(){
    webform_node_view(node_load(1), 'full');
    return '<div id="utf-signin-dialog-block" class="zoom-anim-dialog mfp-hide dialog-with-tabs">
  <div class="utf-signin-form-part">
    <ul class="utf-popup-tabs-nav-item">
      <li><a href="#login" title="Đăng ký tư vấn">'.t('ĐĂNG KÝ TƯ VẤN').'</a></li>
    </ul>
    <div class="utf-popup-container-part-tabs">
      <div class="utf-popup-tab-content-item" id="login">
        <div class="utf-welcome-text-item">
          <h3>'.t('CHÀO MỪNG ĐẾN VỚI PACIFIC MANPOWER').'</h3>
          <span>Bạn có thể gọi cho chúng tôi qua hotline <a href="tel:'.str_replace('.','',str_replace(' ','',getNodeContent(32))).'">'.str_replace('.','',str_replace(' ','',getNodeContent(32))).'!</a></span>
        </div>
        '.theme_webform_view(node_load(1)->content).'
      </div>
    </div>
  </div>
</div>
    ';
  }





?>

