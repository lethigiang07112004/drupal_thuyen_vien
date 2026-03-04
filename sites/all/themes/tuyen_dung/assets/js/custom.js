(function ($) {
  Drupal.behaviors.mymodule = {
    attach: function (context, settings) {
      $(document).ready(function () {
        "use strict";
        if ($('.utf-intro-banner-search-form-block')[0]) {
          setTimeout(function(){
            $(".pac-container").prependTo(".utf-intro-search-field-item.with-autocomplete");
          }, 300);
        }
        var typed = new Typed('.typed-words', {
          strings: ["Web Designer."," Graphic Designer."," Logo Designer."," Sales Marketing."],
          typeSpeed: 80,
          backSpeed: 80,
          backDelay: 4000,
          startDelay: 1000,
          loop: true,
          showCursor: true
        });
      })
    }
  }
}(jQuery));
