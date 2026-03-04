<?php $ds=taxonomy_term_load_multiple(array(), array('vid'=>taxonomy_vocabulary_get_names()['danh_sach_nganh']->vid)); ?>
<?php $arr=array();?>
<div class="row">
  <div class="col-md-9">
    <div class="back_page_tab_nav">
      <div class="page_tab_nav">
        <ul class="nav nav-tabs">
          <?php $dsrun=0;?>
          <?php foreach ($ds as $id => $dsitem): ?>
            <li class="nav-item">
              <a class="nav-link" title="<?=$dsitem->name;?>" <?php if($dsrun==0) print 'active'?>" data-toggle="pill" href="#home<?=$dsitem->tid?>"><?=$dsitem->name;?></a>
              <?php $dsrun++;?>
            </li>
          <?php endforeach;?>
        </ul>
      </div>
      <div class="tab-content">
        <?php foreach ($rows as $row): ?>
          <?php $ex=explode('{{}}',$row);?>
          <?php $ds_id_loai_hang=explode(',',strip_tags($ex[9]));?>
          <?php foreach ($ds_id_loai_hang as $item_tid):?>
            <?php $arr[trim($item_tid)][]=$row;?>
          <?php endforeach;?>
        <?php endforeach;?>
        <?php $id_tab_run=0;?>
        <?php foreach ($arr as $id_tab => $item):?>
          <div class="tab-pane <?php ($id_tab_run==0) ? print 'active' : print 'fade';?>" id="home<?=$id_tab?>">
            <?php $id_tab_run++;?>
            <div class="table-responsive">
              <table class="table table-hover table-edit-tab table">
                <thead>
                <tr>
                  <th class="text-center"><?=t('Mã')?></th>
                  <th><?=t('Công việc')?></th>
                  <th><?=t('Giới tính')?></th>
                  <th><?=t('Số lượng')?></th>
                  <th><?=t('Nơi làm việc')?></th>
                  <th><?=t('Lương cơ bản')?></th>
                  <th><?=t('Thời hạn')?></th>
                  <th class="text-center"><?=t('Tình trạng')?></th>
                </tr>
                </thead>
                <tbody>
                <?php foreach ($item as $item_new):?>
                  <?php $ex=explode('{{}}',$item_new);?>
                  <tr>
                    <td><?=$ex[0]?></td>
                    <td><?=$ex[1]?></td>
                    <td class="text-center"><?=$ex[2]?></td>
                    <td class="text-center"><?=$ex[3]?></td>
                    <td class="text-center"><?=$ex[4]?></td>
                    <td><?=$ex[5]?></td>
                    <td><?=$ex[6]?><br><?=$ex[7]?></td>
                    <td class="text-center">
                      <?=$ex[8]?>
                      <br>
                      <?=l('Xem thêm',$ex[10],array(
                        'attributes' => array(
                          'class'=>array('view_more'),
                          'title' => $item['link']['link_title']
                        ),
                        'html' => true
                      ))?>
                    </td>
                  </tr>
                <?php endforeach;?>
                </tbody>
              </table>
            </div>
          </div>
        <?php endforeach;?>
      </div>
    </div>
  </div>
  <div class="col-md-3">
    <?=views_embed_view('block_front','block_tuyen_dung_noi_bat')?>
  </div>
</div>
