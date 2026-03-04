<div id="wrapper">
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
            <a href="#utf-signin-dialog-block" class="popup-with-zoom-anim log-in-button" title="<?=t('ĐĂNG KÝ TƯ VẤN')?>"><i class="icon-line-awesome-pencil"></i> <span><?=t('ĐĂNG KÝ TƯ VẤN')?></span></a>
          </div>
          <span class="mmenu-trigger">
            <button class="hamburger utf-hamburger-collapse-item" type="button"> <span class="utf-hamburger-box-item"> <span class="utf-hamburger-inner-item"></span> </span> </button>
          </span>
        </div>
      </div>
    </div>
  </header>
  <div class="clearfix menu_fix"></div>
  <div id="titlebar" class="gradient">
      <div class="brc w-100"><img src="/sites/default/files/bg-trangcon.jpg" alt="Breadcrumb" class="img-fluid w-100"></div>
    <div class="container">
      <div class="row">
        <div class="col-md-12">
          <h1><?=$title?></h1>
          <nav id="breadcrumbs">
            <ul>
              <?php $breadcrumb_array = drupal_get_breadcrumb(); ?>
              <?php $run_bread = 0; ?>
              <?php foreach ($breadcrumb_array as $item_breadcrumb_array): ?>
                <?php $run_bread++; ?>
                <li class="<?php ($run_bread != 1) ? print 'ml-5' : print ''; ?>">
                  <?= $item_breadcrumb_array ?>
                </li>
              <?php endforeach; ?>
              <li><?php isset($title) ? print $title : print ''; ?></li>
            </ul>
          </nav>
        </div>
      </div>
    </div>
  </div>
  <div class="<?php (arg(0)=='don-hang-xkld') ? print 'container-fluid' : print 'container'?>">
    <div class="utf-companies-list-aera">
      <?php if ($tabs): ?>
        <div class="tabs"><?php print render($tabs); ?></div><?php endif; ?>
      <?php if ($action_links): ?>
        <ul class="action-links"><?php print render($action_links); ?></ul><?php endif; ?>
      <?=getnodecontent(31)?>
      <div class="row">
        <div class="col-md-6">
          <div class="utf-contact-form-item">
              <p>Send us your request</p>
                  <?php webform_node_view(node_load(1),'full');
                  print theme_webform_view(node_load(1)->content); ?>
          </div>
        </div>
        <div class="col-md-6">
          <?php print render($page['content']); ?>
        </div>
      </div>
    </div>
  </div>
    <div id="footer" class="mt-50">
        <div class="utf-footer-section-item-block">
            <div class="container">
                <div class="row">
                    <div class="col-xl-5 col-md-12">
                        <div class="utf-footer-item-links">
<!--                            <a href="--><?php //=$front_page?><!--" title="Ảnh logo tuyển dụng thuyển viên" class="footer-logo mb-5"><img src="/sites/default/files/logo-footer.png" alt="Ảnh LOGO THUYỀN VIÊN"></a>-->
                            <h3><?= t('CONTACT') ?></h3>
                          <?=getnodecontent(25)?>
                        </div>
                    </div>
                    <div class="col-md-4 mb-mb-30">
                        <div class="row">
                            <div class="col-xl-8 col-12 offset-xl-3">
                                <div class="utf-footer-item-links ml-50 ml-mb-0">
                                    <h3><?=t('LINKS')?></h3>
                                  <?=menufooter();?>
                                </div>
                            </div>

                            <!--              <div class="col-xl-6 col-7">-->
                            <!--                <div class="utf-footer-item-links">-->
                            <!--                  --><?//=views_embed_view('danh_muc_nganh','block_list_job')?>
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
                    <div class="col-xl-12"><?=getnodecontent(27)?></div>
                </div>
            </div>
        </div>
    </div>
</div>
<?= form_dang_ky();?>
