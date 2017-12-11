/**

GDevelop - ParentingBehavior Extension
Copyright (c) 2018 Franco Maciel (francomaciel10@gmail.com)
This project is released under the MIT License.
*/

/**
 * @namespace gdjs
 * @class Transform
 * @static
 * @private
 */
gdjs.Transform = function(a=1.0, b=0.0, c=0.0, d=1.0, tx=0.0, ty=0.0)
{
	this.a = a;
	this.b = b;
	this.c = c;
	this.d = d;
	this.tx = tx;
	this.ty = ty;
};

gdjs.Transform.data = {x:0.0, y:0.0, rot:0.0, sx:1.0, sy:1.0};
gdjs.Transform.degToRad = Math.PI / 180.0;
gdjs.Transform.radToDeg = 180.0 / Math.PI;

gdjs.Transform.prototype.clone = function(){
	return new gdjs.Transform(this.a, this.b, this.c, this.d, this.tx, this.ty);
};

gdjs.Transform.prototype.set = function(x, y, rot, sx, sy){
	var sinRot = Math.sin(rot * gdjs.Transform.degToRad);
	var cosRot = Math.cos(rot * gdjs.Transform.degToRad);

	this.a =  sx * cosRot;
	this.b = -sy * sinRot;
	this.c =  sx * sinRot;
	this.d =  sy * cosRot;
	this.tx = x;
	this.ty = y;
};

gdjs.Transform.prototype.decompose = function(){
	var data = gdjs.Transform.data;

	data.x = this.tx;
	data.y = this.ty;
	data.sx = Math.sqrt(this.a*this.a + this.c*this.c);
	data.sy = Math.sqrt(this.b*this.b + this.d*this.d);
	data.rot = Math.atan2(-this.b/data.sy, this.a/data.sx) * gdjs.Transform.radToDeg;

	return data;
};

gdjs.Transform.prototype.mul = function(trfm){
	var this_a = this.a;
	var this_b = this.b;
	var this_c = this.c;
	var this_d = this.d;
	var this_tx = this.tx;
	var this_ty = this.ty;

	this.a = this_a*trfm.a + this_b*trfm.c;
	this.b = this_a*trfm.b + this_b*trfm.d;
	this.c = this_c*trfm.a + this_d*trfm.c;
	this.d = this_c*trfm.b + this_d*trfm.d;
	this.tx = this_a*trfm.tx + this_b*trfm.ty + this_tx;
	this.ty = this_c*trfm.tx + this_d*trfm.ty + this_ty;

	return this;
};

gdjs.Transform.prototype.cloneMul = function(trfm){
	return new gdjs.Transform(this.a*trfm.a + this.b*trfm.c,
							  this.a*trfm.b + this.b*trfm.d,
							  this.c*trfm.a + this.d*trfm.c,
							  this.c*trfm.b + this.d*trfm.d,
							  this.a*trfm.tx + this.b*trfm.ty + this.tx,
							  this.c*trfm.tx + this.d*trfm.ty + this.ty);
};

gdjs.Transform.prototype.inv = function(){
	var this_a = this.a;
	var this_b = this.b;
	var this_c = this.c;
	var this_d = this.d;
	var this_tx = this.tx;
	var this_ty = this.ty;

	var det_inv = 1.0 / (this.a*this.d - this.b*this.c);
	this.a =  this_d*det_inv;
	this.b = -this_b*det_inv;
	this.c = -this_c*det_inv;
	this.d =  this_a*det_inv;
	this.tx = (this_b*this_ty - this_d*this_tx)*det_inv;
	this.ty = (this_c*this_tx - this_a*this_ty)*det_inv;
	
	return this;
};

gdjs.Transform.prototype.cloneInv = function(){
	var det_inv = 1.0 / (this.a*this.d - this.b*this.c);
	return new gdjs.Transform( this.d*det_inv,
							  -this.b*det_inv,
							  -this.c*det_inv,
							   this.a*det_inv,
							  (this.b*this.ty - this.d*this.tx)*det_inv,
							  (this.c*this.tx - this.a*this.ty)*det_inv);
};
