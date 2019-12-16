// var splitHeadline = function(headline) {
// var splitter = /<br>/gi,
// 	wrapper  = document.createElement('p');
//
// 	headline = headline.replace('>', '><span>'); // add extra opening span for first word
// 	headline = headline.replace('</', '</span></'); // add extra closing span for last word
// 	headline = headline.replace(splitter, '</span><span>'); // replace <br> with spans
//
// 	wrapper.classList.add('text-wrapper');
// 	wrapper.innerHTML = headline; // wrap headline with identifier
//
// 	return wrapper;
// }

var splitHeadline = function(headline, targetIdName, targetClass) {

	var lines = headline.split("<br>");
	var newHeadlineContainer = "";
	var headline_id = targetIdName;
	var headline_class = targetClass;

	for (var i=0; i<lines.length; i++){
		var newSpan = "<p id='" + (headline_id + i) + "' class='" + headline_class + "'>";
		newSpan += lines[i];
		newSpan += "</p>";

		if (i < lines.length && i != lines.length-1) {
			newSpan += "<br>";
		}

		newHeadlineContainer += newSpan;
	}

	return newHeadlineContainer;
}

var splitHeadline_clone = function(headline) {

	var lines = headline.split("<br>");
	var newHeadlineContainer = "";
	var headline_id = "headlineSpan_clone";
	var headline_class = "headline1_span_clone";

	for (var i=0; i<lines.length; i++){
		var newSpan = "<p id='" + (headline_id + i) + "' class='" + headline_class + "'>";
		newSpan += lines[i];
		newSpan += "</p>";

		if (i < lines.length && i != lines.length-1) {
			newSpan += "<br>";
		}

		newHeadlineContainer += newSpan;
	}

	return newHeadlineContainer;
}

var splitHeadline2 = function(headline, targetIdName, targetClass) {

	var lines = headline.split("<br>");
	var newHeadlineContainer = "";
	var headline_id = targetIdName;
	var headline_class = targetClass;

	for (var i=0; i<lines.length; i++){
		var newSpan = "<p id='" + (headline_id + i) + "' class='" + headline_class + "'>";
		newSpan += lines[i];
		newSpan += "</p>";

		if (i < lines.length && i != lines.length-1) {
//			newSpan += "<br>";
		}

		newHeadlineContainer += newSpan;
	}

	return newHeadlineContainer;
}

