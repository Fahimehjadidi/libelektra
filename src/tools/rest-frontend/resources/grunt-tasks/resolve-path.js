'use strict';

var path = require('path');

module.exports = function(check_path) {
	if(path.isAbsolute(check_path)) {
		return path.normalize(check_path);
	} else {
		return path.normalize(path.join(path.dirname(__dirname), '..', check_path));
	}
};