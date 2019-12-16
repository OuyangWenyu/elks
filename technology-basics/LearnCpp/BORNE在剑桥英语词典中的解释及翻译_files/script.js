
var tl;
function initThis(){
	addListeners(); 
	animate();

}

function elemId(id) {
	return document.getElementById(id);
}

function addListeners() {
    elemId('btn_bg1').addEventListener('mouseover', onOverHandler);
    elemId('btn_bg1').addEventListener('mouseout', onOutHandler);
}
function onOverHandler(){
    //TweenMax.to('#cta-arrow', .15, {x:2});
    //console.log("!!!!!");
}
function onOutHandler(){
    //TweenMax.to('#cta-arrow', .15, {x:0});
}
function animate() {
  tl = TweenMax;
  tl.set('#container_dc', {display:"block", opacity:1});
  tl.set('#footer', {y:0});
  tl.set('#logo', {opacity:1});
  tl.set(['#f1_c1', "#f1_c2"], {x:20});
  tl.set('#f2_c1', {x:40});
  tl.set('#f2_c2', {x:40});
  tl.set('#bg1', {scale:1.2, x:30});
  tl.set('#bg2', {scale:1.2, x:30});
  
  tl.to('#footer', .5, {y:0, ease:Power1.easeInOut});
  tl.to('#bg1', 2.5, {x:0, rotationZ: 0.01, force3D: false, scale:1});
  tl.to('#logo', .15, {opacity:1, ease:Power0. easeInOut, delay:.25});
  tl.to('#f1_c1', .75, {x:0, y:0, opacity:1, rotationZ: 0.01, force3D: false, delay:.25});
  tl.to('#f1_c2', .75, {x:0, y:0, opacity:1, rotationZ: 0.01, force3D: false, delay:.75});
  
  tl.delayedCall(2.5, scene2);
      
} 
function scene2(){
  tl.to('#f1_c1', .5, {opacity:0});
  tl.to('#f1_c2', .5, {opacity:0});
  tl.to('#bg2', 2.5, {opacity:1, x:0, rotationZ: 0.01, force3D: false, scale:1});
  // tl.to('#logo', .85, {x:-11, rotationZ: 0.01, force3D: false});
  tl.to('#f2_c1', .85, {opacity:1, x:0, y:0, rotationZ: 0.01, force3D: false, delay:.25});
  tl.to('#f2_c2', .85, {opacity:1, x:0, y:0, rotationZ: 0.01, force3D: false, delay:.75});
    
  tl.delayedCall(2.5, scene3);
  
  tl.set('#bg3', {scale:1.2, x:30});
  
}
function scene3(){
  tl.to('#frame3', .5, {opacity:1});
  tl.to('#bg3', 2.5, {x:0, rotationZ: 0.01, force3D: false, scale:1});
  tl.to('#f3_c1', .85, {opacity:1, x:0, y:0, rotationZ: 0.01, force3D: false, delay:.25});
  tl.to('#f3_c2', .85, {opacity:1, x:0, y:0, rotationZ: 0.01, force3D: false, delay:.75});
    
  tl.delayedCall(3.25, scene4);

  tl.set('#logo-large', {opacity:0, rotationZ: 0.01, force3D: false, scale:1.2});
  tl.set('#f4_c1', {opacity:0});
  tl.set('#cta', {opacity:0, scale:.75});
}
function scene4(){
    tl.to('#center', .15, {opacity:0});
    tl.to('#frame4', .15, {opacity:1});
    tl.to('#logo-large', 1, {opacity:1, rotationZ: 0.01, force3D: false, scale:1});
    tl.to('#f4_c1', 1, {opacity:1, delay:.5});
    tl.to('#cta', 1, {opacity:1, delay:.75});
    tl.to('#cta', 1, {scale:1, ease:Elastic.easeOut.config(0.5, 0.0), delay:.75});
}

setTimeout(initThis,1500);