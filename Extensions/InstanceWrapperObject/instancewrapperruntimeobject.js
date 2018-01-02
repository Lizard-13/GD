/**

GDevelop - Instance Wrapper Object Extension
Copyright (c) 2017-2018 Franco Maciel (francomaciel10@gmail.com)
This project is released under the MIT License.
*/

gdjs.InstanceWrapperObject = function(runtimeScene, objectData){
    gdjs.RuntimeObject.call(this, runtimeScene, objectData);
    this.instance = null;
};

gdjs.InstanceWrapperObject.prototype = Object.create(gdjs.RuntimeObject.prototype);
gdjs.InstanceWrapperObject.thisIsARuntimeObjectConstructor = "InstanceWrapperObject::InstanceWrapper";

gdjs.InstanceWrapperObject.prototype.setInstance = function(instance){
    if(this.instance !== instance){
        this.clearInstance();
        this.instance = instance;
    }
};

gdjs.InstanceWrapperObject.prototype.clearInstance = function(){
    this.instance = null;
};

gdjs.InstanceWrapperObject.prototype.deleteFromScene = function(runtimeScene){
    if(!this.empty()){
        this.instance.deleteFromScene(runtimeScene);
        this.clearInstance();
    }
    else{
        gdjs.RuntimeObject.prototype.deleteFromScene.call(this, runtimeScene);
    }
};

gdjs.InstanceWrapperObject.currentInstance = function(instanceWrapper, objectLists, inverted){
    if(instanceWrapper.empty()){
        return false;
    }

    return gdjs.evtTools.object.pickObjectsIf(function(object){
                                                  if(gdjs.InstanceWrapperObject.prototype.isPrototypeOf(object)){
                                                      return object.instance === instanceWrapper.instance;
                                                  }
                                                  return object === instanceWrapper.instance;
                                              },
                                              objectLists, inverted);
};

gdjs.InstanceWrapperObject.prototype.empty = function(){
    if(this.instance && !this.instance.livingOnScene){
        this.instance = null;
    }
    return this.instance === null;
};

gdjs.InstanceWrapperObject.prototype.getInstance = function(){
    return this.instance;
};

gdjs.InstanceWrapperObject.prototype.getElapsedTime = function(runtimeScene){
    if(!this.empty()){
        return this.instance.getElapsedTime(runtimeScene);
    }
    return gdjs.RuntimeObject.prototype.getElapsedTime.call(this, runtimeScene);
};

gdjs.InstanceWrapperObject.prototype.getUniqueId = function(){
    if(!this.empty()){
        return this.instance.getUniqueId();
    }
    return gdjs.RuntimeObject.prototype.getUniqueId.call(this);
};

gdjs.InstanceWrapperObject.prototype.getX = function(){
    if(!this.empty()){
        return this.instance.getX();
    }
    return gdjs.RuntimeObject.prototype.getX.call(this);
};

gdjs.InstanceWrapperObject.prototype.setX = function(x){
    if(!this.empty()){
        this.instance.setX(x);
        return;
    }
    gdjs.RuntimeObject.prototype.setX.call(this, x);
};

gdjs.InstanceWrapperObject.prototype.getY = function(){
    if(!this.empty()){
        return this.instance.getY();
    }
    return gdjs.RuntimeObject.prototype.getY.call(this);
};

gdjs.InstanceWrapperObject.prototype.setY = function(y){
    if(!this.empty()){
        this.instance.setY(y);
        return;
    }
    gdjs.RuntimeObject.prototype.setY.call(this, y);
};

gdjs.InstanceWrapperObject.prototype.getAngle = function(){
    if(!this.empty()){
        return this.instance.getAngle();
    }
    return gdjs.RuntimeObject.prototype.getAngle.call(this);
};

gdjs.InstanceWrapperObject.prototype.setAngle = function(angle){
    if(!this.empty()){
        this.instance.setAngle(angle);
        return;
    }
    gdjs.RuntimeObject.prototype.setAngle.call(this, angle);
};

gdjs.InstanceWrapperObject.prototype.getWidth = function(){
    if(!this.empty()){
        return this.instance.getWidth();
    }
    return gdjs.RuntimeObject.prototype.getWidth.call(this);
};

gdjs.InstanceWrapperObject.prototype.setWidth = function(w){
    if(!this.empty()){
        this.instance.setWidth(w);
        return;
    }
    gdjs.RuntimeObject.prototype.setWidth.call(this, w);
};

gdjs.InstanceWrapperObject.prototype.getHeight = function(){
    if(!this.empty()){
        return this.instance.getHeight();
    }
    return gdjs.RuntimeObject.prototype.getHeight.call(this);
};

gdjs.InstanceWrapperObject.prototype.setHeight = function(h){
    if(!this.empty()){
        this.instance.setHeight(h);
        return;
    }
    gdjs.RuntimeObject.prototype.setHeight.call(this, h);
};

gdjs.InstanceWrapperObject.prototype.getCenterX = function(){
    if(!this.empty()){
        return this.instance.getCenterX();
    }
    return gdjs.RuntimeObject.prototype.getCenterX.call(this);
};

gdjs.InstanceWrapperObject.prototype.getCenterY = function(){
    if(!this.empty()){
        return this.instance.getCenterY();
    }
    return gdjs.RuntimeObject.prototype.getCenterY.call(this);
};

gdjs.InstanceWrapperObject.prototype.getDrawableX = function(){
    if(!this.empty()){
        return this.instance.getDrawableX();
    }
    return gdjs.RuntimeObject.prototype.getDrawableX.call(this);
};

gdjs.InstanceWrapperObject.prototype.getDrawableY = function(){
    if(!this.empty()){
        return this.instance.getDrawableY();
    }
    return gdjs.RuntimeObject.prototype.getDrawableY.call(this);
};

gdjs.InstanceWrapperObject.prototype.getZOrder = function(){
    if(!this.empty()){
        return this.instance.getZOrder();
    }
    return gdjs.RuntimeObject.prototype.getZOrder.call(this);
};

gdjs.InstanceWrapperObject.prototype.setZOrder = function(z){
    if(!this.empty()){
        this.instance.setZOrder(z);
        return;
    }
    gdjs.RuntimeObject.prototype.setZOrder.call(this, z);
};

gdjs.InstanceWrapperObject.prototype.hide = function(enable){
    if(!this.empty()){
        this.instance.hide(enable);
        return;
    }
    gdjs.RuntimeObject.prototype.hide.call(this, enable);
};

gdjs.InstanceWrapperObject.prototype.isVisible = function(){
    if(!this.empty()){
        return this.instance.isVisible();
    }
    return gdjs.RuntimeObject.prototype.isVisible.call(this);
};

gdjs.InstanceWrapperObject.prototype.isHiden = function(){
    if(!this.empty()){
        return this.instance.isHiden();
    }
    return gdjs.RuntimeObject.prototype.isHiden.call(this);
};

gdjs.InstanceWrapperObject.prototype.getLayer = function(){
    if(!this.empty()){
        return this.instance.getLayer();
    }
    return gdjs.RuntimeObject.prototype.getLayer.call(this);
};

gdjs.InstanceWrapperObject.prototype.setLayer = function(layer){
    if(!this.empty()){
        this.instance.setLayer(layer);
        return;
    }
    gdjs.RuntimeObject.prototype.setLayer.call(this, layer);
};

gdjs.InstanceWrapperObject.prototype.getVariables = function(){
    if(!this.empty()){
        return this.instance.getVariables();
    }
    return gdjs.RuntimeObject.prototype.getVariables.call(this);
};

gdjs.InstanceWrapperObject.prototype.hasVariable = function(name){
    if(!this.empty()){
        return this.instance.hasVariable(name);
    }
    return gdjs.RuntimeObject.prototype.hasVariable.call(this, name);
};

gdjs.InstanceWrapperObject.prototype.addForce = function(x, y, clearing){
    if(!this.empty()){
        this.instance.addForce(x, y, clearing);
        return;
    }
    gdjs.RuntimeObject.prototype.addForce.call(this, x, y, clearing);
};

gdjs.InstanceWrapperObject.prototype.addPolarForce = function(angle, len, clearing){
    if(!this.empty()){
        this.instance.addPolarForce(angle, len, clearing);
        return;
    }
    gdjs.RuntimeObject.prototype.addPolarForce.call(this, angle, len, clearing);
};

gdjs.InstanceWrapperObject.prototype.addForceTowardPosition = function(x, y, len, clearing){
    if(!this.empty()){
        this.instance.addForceTowardPosition(x, y, len, clearing);
        return;
    }
    gdjs.RuntimeObject.prototype.addForceTowardPosition.call(this, x, y, len, clearing);
};

gdjs.InstanceWrapperObject.prototype.clearForces = function(){
    if(!this.empty()){
        this.instance.clearForces();
        return;
    }
    gdjs.RuntimeObject.prototype.clearForces.call(this);
};

gdjs.InstanceWrapperObject.prototype.hasNoForces = function(globalUpdate=false){
    if(globalUpdate){
        return true;
    }
    if(!this.empty()){
        return this.instance.hasNoForces();
    }
    return gdjs.RuntimeObject.prototype.hasNoForces.call(this, globalUpdate);
};

gdjs.InstanceWrapperObject.prototype.getAverageForce = function(){
    if(!this.empty()){
        return this.instance.getAverageForce();
    }
    return gdjs.RuntimeObject.prototype.getAverageForce.call(this);
};

gdjs.InstanceWrapperObject.prototype.getHitBoxes = function(){
    if(!this.empty()){
        return this.instance.getHitBoxes();
    }
    return gdjs.RuntimeObject.prototype.getHitBoxes.call(this);
};

gdjs.InstanceWrapperObject.prototype.updateHitBoxes = function(){
    if(!this.empty()){
        this.instance.updateHitBoxes();
    }
    gdjs.RuntimeObject.prototype.updateHitBoxes.call(this);
};

gdjs.InstanceWrapperObject.prototype.getBehavior = function(name){
    if(!this.empty()){
        return this.instance.getBehavior(name);
    }
    return gdjs.RuntimeObject.prototype.getBehavior.call(this, name);
};

gdjs.InstanceWrapperObject.prototype.hasBehavior = function(name){
    if(!this.empty()){
        return this.instance.hasBehavior(name);
    }
    return gdjs.RuntimeObject.prototype.hasBehavior.call(this, name);
};

gdjs.InstanceWrapperObject.prototype.activateBehavior = function(name, enable){
    if(!this.empty()){
        this.instance.activateBehavior(name, enable);
    }
    gdjs.RuntimeObject.prototype.activateBehavior.call(this, name, enable);
};

gdjs.InstanceWrapperObject.prototype.behaviorActivated = function(name){
    if(!this.empty()){
        return this.instance.behaviorActivated(name);
    }
    return gdjs.RuntimeObject.prototype.behaviorActivated.call(this, name);
};
