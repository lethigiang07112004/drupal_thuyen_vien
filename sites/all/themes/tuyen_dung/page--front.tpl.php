<?php print render($page['content']['metatags']); ?>
<div id="wrapper">
  <!-- Header Container -->
  <div id="logo">
    <a href="<?= $front_page ?>" title="Ảnh logo tuyển dụn
  <div class=" name_company_menu" data-name="<?php isset(node_load(2)->title) ? print node_load(2)->title : print t('PACIFIC MANPOWER') ?>">
  </div>
  <header id="utf-header-container-block">
    <div id="header">
      <div class="container">
        <div class="utf-left-side">
          <div id="logo">
            <a href="<?= $front_page ?>" title="Ảnh logo tuyển dụng thuyển viên"><img src="<?= $logo ?>"
                alt="Ảnh LOGO THUYỀN VIÊN"></a>
          </div>

          <nav id="navigation">
            <?= getMainMenu() ?>
          </nav>
          <div class="clearfix"></div>
        </div>
        <div class="utf-right-side">
          <div class="utf-header-widget-item">
            <a href="#utf-signin-dialog-block" class="popup-with-zoom-anim log-in-button" title="<?= t('ĐĂNG KÝ TƯ VẤN') ?>"><i class="icon-line-awesome-pencil"></i> <span><?= t('ĐĂNG KÝ TƯ VẤN') ?></span></a>
          </div>
          <span class="mmenu-trigger">
            <button class="hamburger utf-hamburger-collapse-item" type="button"> <span class="utf-hamburger-box-item"> <span class="utf-hamburger-inner-item"></span> </span> </button>
          </span>
        </div>
      </div>
    </div>
  </header>
  <div class="clearfix menu_fix"></div>


  <?php if ($page['main_frontend']) {
    print render($page['main_frontend']);
  } ?>
  <!--  <div class="container-fluid mt-60">-->
  <!--    <div class="row mb-60">-->
  <!--      <div class="col-md-3">-->
  <!--        <div class="pricing-plan recommended">-->
  <!--          <a href="/" class="button utf-ripple-effect-dark utf-button-sliding-icon full-width mb-20 mb-mb-0" title="Danh mục"><i class="icon-feather-align-left"></i>--><? //=t('DANH MỤC')
                                                                                                                                                                              ?><!--</a><div class="utf-pricing-plan-features-item">-->
  <!--            --><? //=getMainMenuDanhMuc()
                      ?>
  <!--          </div>-->
  <!--        </div>-->
  <!--      </div>-->
  <!--      <div class="col-md-9">-->
  <!--        <div class="back-right-font">-->
  <!--          <div class="row">-->
  <!--            <div class="col-md-6">-->
  <!--              --><? //=views_embed_view('block_front','block_tin_tuc_gan_day')
                        ?>
  <!--            </div>-->
  <!--            <div class="col-md-6">-->
  <!--              --><? //=views_embed_view('block_front','block_tin_tuc_khac')
                        ?>
  <!--            </div>-->
  <!--          </div>-->
  <!--        </div>-->
  <!--      </div>-->
  <!--    </div>-->
  <!--  </div>-->
  <?php if ($page['main_frontend_center']) {
    print html_entity_decode(render($page['main_frontend_center']));
  } ?>
  <!--  <div class="color_title_white utf-photo-section-block padding-top-60 padding-bottom-60" data-background-image="--><? //=trim(strip_tags(views_embed_view('config_blog','block_hoi_dap')));
                                                                                                                          ?><!--">-->
  <!--    <div class="container">-->
  <!--      <div class="utf-section-headline-item centered margin-top-0 margin-bottom-60">-->
  <!--        <h3 class="about_us">--><? //=t('HỎI ĐÁP THẮC MẮC')
                                      ?><!--</h3>-->
  <!--        <div class="utf-headline-display-inner-item">--><? //=t('Pacific Manpower')
                                                              ?><!--</div>-->
  <!--      </div>-->
  <!--      <div class="row">-->
  <!--        <div class="col-md-6">-->
  <!--          --><?php //webform_node_view(node_load(1),'full');
                    //          print theme_webform_view(node_load(1)->content); 
                    ?>
  <!--        </div>-->
  <!--        <div class="col-md-6">-->
  <!--          --><? //=views_embed_view('block_front','block_hoi_dap')
                    ?>
  <!--        </div>-->
  <!--      </div>-->
  <!--    </div>-->
  <!--  </div>-->
  <?php if ($page['main_frontend_after']) {
    print render($page['main_frontend_after']);
  } ?>
  <div id="footer">
    <div class="utf-footer-section-item-block">
      <div class="container">
        <div class="row">
          <div class="col-xl-5 col-md-12">
            <div class="utf-footer-item-links">
              <!--              <a href="--><?php //=$front_page
                                            ?><!--" title="Ảnh logo tuyển dụng thuyển viên" class="footer-logo mb-5"><img src="/sites/default/files/logo-footer.png" alt="Ảnh LOGO THUYỀN VIÊN"></a>-->
              <h3><?= t('CONTACT') ?></h3>
              <?= getnodecontent(25) ?>
            </div>
          </div>
          <div class="col-md-4 mb-mb-30">
            <div class="row">
              <div class="col-xl-8 col-12 offset-xl-3">
                <div class="utf-footer-item-links ml-50 ml-mb-0">
                  <h3><?= t('LINKS') ?></h3>
                  <?= menufooter(); ?>
                </div>
              </div>

              <!--              <div class="col-xl-6 col-7">-->
              <!--                <div class="utf-footer-item-links">-->
              <!--                  --><? //=views_embed_view('danh_muc_nganh','block_list_job')
                                        ?>
              <!--                </div>-->
              <!--              </div>-->
            </div>
          </div>
          <div class="col-xl-3">
            <div class="utf-footer-item-links">

              <h3><?= t('MAPS') ?></h3>

              <?= getnodecontent(26) ?>
            </div>

          </div>
        </div>
      </div>
    </div>
    <div class="utf-footer-copyright-item">
      <div class="container">
        <div class="row">
          <div class="col-xl-12"><?= getnodecontent(27) ?></div>
        </div>
      </div>
    </div>
  </div>
</div>
<?= form_dang_ky(); ?>
<div class="my-link">
  <a href="/thong-tin">Gửi hồ sơ </a>
</div>
<style type="text/css">
  .my-link a {
    position: fixed;
    bottom: 80px;
    right: 20px;
    background: #eeeeee;
    color: #333 !important;
    padding: 12px 25px;
    border-radius: 30px;
    font-weight: bold;
    text-decoration: none;
    z-index: 9999999999;
    box-shadow: 0 4px 10px rgba(0, 0, 0, 0.3);
    font-family: Arial, sans-serif;
    display: block !important;
  }

  .my-link:hover {
    background: #eeeeee;
    color: #333 !important;
  }
</style>