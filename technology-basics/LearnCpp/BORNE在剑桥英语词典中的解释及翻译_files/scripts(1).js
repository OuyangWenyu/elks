var ad = document.getElementById("ad");
//------------------------------------------*/
// PRELOAD BOOLEAN
/*------------------------------------------*/
var isWindowLoaded_bool = false;
var isPoliteLoad_bool = false;
var isIALoaded_bool = false;
var isImagesLoaded_bool = false;

//------------------------------------------*/
// PRELOAD SET INTERVALS
/*------------------------------------------*/
var politeLoad_intv = setInterval(politePreloader, 1);

//------------------------------------------*/
// Global variable
/*------------------------------------------*/


/*========================================================================*/
// FUNCTIONS - PRELOADERS
/*========================================================================*/
// WINDOW PRELOADER
/*------------------------------------------*/
// Checks to see if window is loaded
window.onload = function () {
    // boolean to determine if browser window is loaded
    isWindowLoaded_bool = true;
    // console.log("isWindowLoaded_bool", isWindowLoaded_bool);
}

/*------------------------------------------*/
// INSTANT AD EVENT LISTENER
/*------------------------------------------*/
// Instant Ad event listener
myFT.on('instantads', function () {

    // document.getElementById("headline1").innerHTML = myFT.instantAds.F1_headline_text;
    document.getElementById("headline1").innerHTML = splitHeadline(myFT.instantAds.F1_headline_text, "headlineSpan", "headline1_span");
    document.getElementById("headline1").style.fontSize = myFT.instantAds.F1_headlineTxt_size_hex.split("|")[0] + "px";
    document.getElementById("headline1").style.color = myFT.instantAds.F1_headlineTxt_size_hex.split("|")[1];

    document.getElementById("headline1_clone").innerHTML = splitHeadline_clone(myFT.instantAds.F1_headline_text);

    document.getElementById("headline2").innerHTML = splitHeadline2(myFT.instantAds.F3_headline_text, "headline2Span", "headline2_span");
    document.getElementById("headline2").style.fontSize = myFT.instantAds.F3_headlineTxt_size_hex.split("|")[0] + "px";
    document.getElementById("headline2").style.color = myFT.instantAds.F3_headlineTxt_size_hex.split("|")[1];

    document.getElementById("borderDiv").style.border = "0px solid " + myFT.instantAds.border_hex;
    document.getElementById("ad").style.backgroundColor = myFT.instantAds.background_hex;

    document.getElementById("cta_text").innerHTML = myFT.instantAds.F3_cta_Text;
    document.getElementById("cta").style.fontSize = myFT.instantAds.F3_ctaTxt_size_hex_xy.split("|")[0] + "px";
    document.getElementById("cta").style.color = myFT.instantAds.F3_ctaTxt_size_hex_xy.split("|")[1];
    document.getElementById("cta").style.left = myFT.instantAds.F3_ctaTxt_size_hex_xy.split("|")[2].split(",")[0] + "px";
    document.getElementById("cta").style.top = myFT.instantAds.F3_ctaTxt_size_hex_xy.split("|")[2].split(",")[1] + "px";

    document.getElementById("phoneImage").src = myFT.instantAds.F3_img;

    myFT.applyClickTag(ad, 1, myFT.instantAds.clicktag_url);
    myFT.applyClickTag(cta, 1, myFT.instantAds.clicktag_url);
    isIALoaded_bool = true;
});


/*------------------------------------------*/
// POLITE LOAD EVENT LISTENER
/*------------------------------------------*/
// This event listener will listen when the polite load event fires
myFT.on('politeload', function (e) {
    // Sets our suload loading boolean to true once parent page is loaded

    isPoliteLoad_bool = true;
});


/*------------------------------------------*/
// POLITE PRELOADER
/*------------------------------------------*/

// Makes sure our window, parent page, IA vars, and feed are loaded before creating our graphic assets
function politePreloader() {
    if (isWindowLoaded_bool && isPoliteLoad_bool && isIALoaded_bool) {
        // clears preloader interval once parent website is loaded
        clearInterval(politeLoad_intv);

        // This function sets up our graphics once instant ads are loaded
        checkImages();
    }
}


//Check if selected Images are loaded then display Ad
function checkImages() {
    var allImages = [
//      "images/phone.png",
      "images/logo_300x250.png"
    ];

    function preloadimages(arr) {
        var newimages = [],
            loadedimages = 0
        var postAction = function () {
        }
        var arr = (typeof arr != "object") ? [arr] : arr

        function imageloadpost() {
            loadedimages++
            if (loadedimages == arr.length) {
                postAction(newimages) //call postaction and pass in newimages array as parameter
            }
        }

        for (var i = 0; i < arr.length; i++) {
            newimages[i] = new Image()
            newimages[i].src = arr[i]
            newimages[i].onload = function () {
                imageloadpost()
            }
            newimages[i].onerror = function () {
                imageloadpost()
            }
        }
        return { //return blank object with done() method
            done: function (f) {
                postAction = f || postAction //remember user defined callback functions to be called when images load
            }
        }
    }

    // Run Unit once all required images are loaded.
    preloadimages(allImages).done(setUp);
}

function setUp() {
  var headline1_lines = document.getElementsByClassName("headline1_span");
  var headline2_lines = document.getElementsByClassName("headline2_span");
  var headline1_lines_clone = document.getElementsByClassName("headline1_span_clone");
  var max_letters_per_line = 24;
  var isCtaAnimating = false;

  var tl = new TimelineLite();
  var tl2 = new TimelineLite();
  var tl3 = new TimelineLite();
    
    tl.set(headline1_lines, {y:20});

  setTimeout(frame1_multiline, 1000); // start frame1 animation.


  // ---------------------------------
  // Show headline1
  // ---------------------------------
  function frame1_multiline() {

    var last_line = headline1_lines[headline1_lines.length-1];
    var last_line_clone = headline1_lines_clone[headline1_lines_clone.length-1];
    var extra_line = myFT.instantAds.F2_headline_text;
    var _temp = last_line.innerHTML + " " + extra_line;
    var lettersCanFit = true;


    if (_temp.length <= max_letters_per_line){
      lettersCanFit = true;
      last_line_clone.outerHTML = "<p style='opacity:0;'>" + last_line.innerHTML + "&nbsp;</p><p id='extra_text'>" + extra_line + "</p>";
      hidden_text_container.innerHTML = extra_line;
    } else {
      lettersCanFit = false;
      last_line_clone.outerHTML = "<p style='opacity:0;'>" + last_line.innerHTML + "</div><br><p id='extra_text'>" + extra_line + "</p>";
      hidden_text_container.innerHTML = extra_line;
    }

    document.getElementById("headline1_clone").style.fontSize = myFT.instantAds.F2_headlineTxt_size_hex.split("|")[0] + "px";
    document.getElementById("headline1_clone").style.color = myFT.instantAds.F2_headlineTxt_size_hex.split("|")[1];

    var extra_line_width = hidden_text_container.offsetWidth;
    var extra_line_height = hidden_text_container.offsetHeight;
    
    
    tl.staggerTo(headline1_lines, 1.2, {y:-50, opacity:1, ease:Power2.easeInOut, force3D:true}, 0.15);
//    tl.staggerTo(headline1_lines, 0.6, {top:0, opacity:1, ease:Power2.easeInOut, force3D:true}, 0.15);
    
    if (extra_line != ""){
      if (lettersCanFit){
        tl.add( TweenLite.to( last_line, 1, {x:"-="+(3+extra_line_width/2), ease:Power2.easeInOut, force3D:true}), "+=0.75" );
        tl.add( TweenLite.to( extra_text, 1, {y:-30, opacity:1, ease:Power2.easeInOut, force3D:true, onComplete:function(){
          setTimeout(frame1_cleanup, 3000);
        }}), "-=1.0");
          
//          tl.add( TweenLite.to( last_line, 1, {right:"+="+(3+extra_line_width/2), ease:Power2.easeInOut, force3D:true}), "+=0.75" );
//        tl.add( TweenLite.to( extra_text, 1, {top:0, opacity:1, ease:Power2.easeInOut, force3D:true, onComplete:function(){
//          setTimeout(frame1_cleanup, 1000);
//        }}), "-=1.0");
          
      } else {
        tl.add( TweenLite.to( headline1, 1, {y:"-="+(extra_line_height/2), ease:Power2.easeInOut, force3D:true}), "+=0.75" );
        var elem = document.getElementById("headline1_clone");
        var lineHeight = Number(window.getComputedStyle(elem, null).getPropertyValue("line-height").replace('px',''));
        var fontSize = Number(window.getComputedStyle(elem, null).getPropertyValue("font-size").replace('px',''));
//        console.log(lineHeight + fontSize)
        var tt = lineHeight + fontSize;
        tl.add( TweenLite.to( extra_text, 1, {y:-tt, opacity:1, ease:Power2.easeInOut, force3D:true, onComplete:function(){
          setTimeout(frame1_cleanup, 3000);
        }}), "-=1.0");
          
//          tl.add( TweenLite.to( headline1, 1, {top:"-="+(extra_line_height/2), ease:Power2.easeInOut, force3D:true}), "+=0.75" );
//        tl.add( TweenLite.to( extra_text, 1, {top:0, opacity:1, ease:Power2.easeInOut, force3D:true, onComplete:function(){
//          setTimeout(frame1_cleanup, 1000);
//        }}), "-=1.0");
          
      }
    } else {
      setTimeout(frame1_cleanup, 4000);
    }

  }

  // ---------------------------------
  // Fade out headline1 one by one
  // ---------------------------------
  function frame1_cleanup() {
      
    tl.staggerTo(headline1_lines, 1.35, {opacity:0, y:"+="+30, ease:Power2.easeInOut, force3D:true}, -0.15);
//    tl.add( TweenLite.to(headline1_lines, 1, {opacity:0, ease:Power2.easeOut, force3D:true}), "-=1.1" );
    tl.add(frame2, "-=0.1");
    TweenLite.to( extra_text, 1.35, {opacity:0, y:"+="+30, ease:Power2.easeInOut, force3D:true});
//    TweenLite.to( extra_text, 1.25, {opacity:0, ease:Power2.easeInOut, force3D:true} );
  }

  // ---------------------------------
  // Reveal gadget and scale down
  // ---------------------------------
  function frame2() {
    tl2.add(
      TweenLite.to( phoneImage, 1.0, {x:0, y:0, scale:1, ease:Power2.easeOut, force3D:true} )
    );

    tl2.add(
      TweenLite.to( phoneImage, 0.5, {opacity:1, ease:Power2.easeOut, force3D:true} ), "-=2.0"
    );

    tl2.add(
      TweenLite.to( borderDiv, 0.5, {borderWidth:"7px 9px 9px 7px", ease:Power2.easeOut, force3D:true} ), "-=0.5"
    );

    tl2.add(
      TweenLite.to( logo, 0.05, {opacity:1} )
    );

    tl2.add(frame3);
      
      tl3.set(headline2_lines, {y:25});
  }

  // ---------------------------------
  // Show headline2
  // ---------------------------------
  function frame3() {
    tl3.staggerTo(headline2_lines, 0.8, {y:-25, opacity:1, ease:Power4.easeOut, force3D:true}, 0.15);
//    tl3.staggerTo(headline2_lines, 0.8, {top:"0", opacity:1, ease:Power4.easeOut, force3D:true}, 0.15);
    tl3.add (
      TweenLite.to( logo, 1.0, {rotationX: 0, ease:Power2.easeOut, force3D:true} ), "-=1.0"
    );

    tl3.add (
      TweenLite.to( cta, 0.5, {y:0, opacity:1} ), "+=0.2"
    );

    tl3.add (cta_onhover, "+=0.5");

    tl3.add (function(){
      cta.addEventListener("mouseover", cta_onhover);
    });
  }


  function cta_onhover() {
    var tl_cta = new TimelineLite();
    var cta_width = cta.offsetWidth;

    if (isCtaAnimating == false) {
      isCtaAnimating = true;
      tl_cta.add (
        TweenLite.to (cta_sheen, 2, {x:cta_width*2, ease:Power4.easeOut, force3D:true} )
      );

      tl_cta.add (
        TweenLite.to (cta_background_glow, 0.75, {opacity:1, ease:Power3.easeOut, force3D:true} ), "-=2.0"
      );

      tl_cta.add (
        TweenLite.to (cta_background_glow, 0.5, {opacity:0, ease:Power3.easeOut, force3D:true} ), "-=1.35"
      );

      tl_cta.add(function(){
        TweenLite.set (cta_sheen, {x:0});
        isCtaAnimating = false;
      }, "-=0.5");
    }
  }
}
