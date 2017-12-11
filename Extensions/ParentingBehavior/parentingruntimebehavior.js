/**

GDevelop - ParentingBehavior Extension
Copyright (c) 2018 Franco Maciel (francomaciel10@gmail.com)
This project is released under the MIT License.
*/

/**
 * @namespace gdjs
 * @class ParentingBehavior
 * @static
 * @private
 */
gdjs.ParentingRuntimeBehavior = function(runtimeScene, behaviorData, owner)
{
	gdjs.RuntimeBehavior.call(this, runtimeScene, behaviorData, owner);

	this.parent = null;
	this.children = [];
	this.transform = new gdjs.Transform();
	this.worldTransform = new gdjs.Transform();
	this._updateTransform = true;
	this._updateWorldTransform = true;
	this._updatedThisFrame = false;
	this.x = 0;
	this.y = 0;
	this.rot = 0;
	this.sx = 1;
	this.sy = 1;
	this._firstTime = true;
	
	this._frame = 0;
};

gdjs.ParentingRuntimeBehavior.prototype = Object.create(gdjs.RuntimeBehavior.prototype);
gdjs.ParentingRuntimeBehavior.thisIsARuntimeBehaviorConstructor = "ParentingBehavior::Parenting";

gdjs.ParentingRuntimeBehavior.prototype.addChild = function(child, keepGlobalTransform)
{
	if (child === null || !child.hasBehavior(this.name)) return;

	var childBehavior = child.getBehavior(this.name);
	if (this.children.indexOf(childBehavior) !== -1) return;
	
	childBehavior._reparentBehavior(this, keepGlobalTransform);

	//~ childBehavior._removeParentBehavior(keepGlobalTransform);
	
	//~ if(keepGlobalTransform){
		//~ this._update(true);
		//~ childBehavior._update(true);
		//~ childBehavior.transform = this.worldTransform.cloneInv().mul(childBehavior.worldTransform);
		//~ childBehavior._updateWorldTransform = true;
	//~ }
	
	//~ childBehavior._reparentBehavior(this, keepGlobalTransform);
	//~ childBehavior.parent = this;
	this.children.push(childBehavior);
	
	this.printData();

};

gdjs.ParentingRuntimeBehavior.prototype._reparentBehavior = function(parentBehavior, keepGlobalTransform)
{
	if (this.parent && keepGlobalTransform){
		this.parent._update(true);
		this._update(true);
		this.transform = this.parent.worldTransform.cloneMul(this.transform);
		this.worldTransform = this.transform.clone();
	}
	
	if (keepGlobalTransform){
		parentBehavior._update(true);
		this._update(true);
		this.transform = parentBehavior.worldTransform.cloneInv().mul(this.worldTransform);
		this.worldTransform = parentBehavior.worldTransform.cloneMul(this.transform);
	}
	
	this.parent = parentBehavior;
};

gdjs.ParentingRuntimeBehavior.prototype.removeChild = function(child, keepGlobalTransform)
{
	if (child === null || !child.hasBehavior(this.name)) return;

	var childBehavior = child.getBehavior(this.name);
	this._removeChildBehavior(childBehavior, keepGlobalTransform);
};

//~ gdjs.ParentingRuntimeBehavior.prototype._removeParentBehavior = function(keepGlobalTransform)
//~ {
	//~ if(this.parent && keepGlobalTransform){
		//~ this.parent._update(true);
		//~ this._update(true);
		//~ this.transform = parent.worldTransform.cloneMul(this.transform);
		//~ this.worldTransform = this.transform.clone();
		//~ this._updateWorldTransform = true;
	//~ }

	//~ this.parent = null;
//~ };

gdjs.ParentingRuntimeBehavior.prototype._removeChildBehavior = function(childBehavior, keepGlobalTransform)
{
	var index = this.children.indexOf(childBehavior);
	
	if (index !== -1){
		this.children.splice(index, 1);
		childBehavior.parent = null;

		if(keepGlobalTransform){
			this._update(true);
			childBehavior._update(true);
			childBehavior.transform = this.worldTransform.cloneMul(childBehavior.transform);
		}
	}
};

//~ gdjs.ParentingRuntimeBehavior.prototype._reparentBehavior = function(parentBehavior, keepGlobalTransform)
//~ {
	//~ if (this.parent) this.parent._removeChildBehavior(this, keepGlobalTransform);
	//~ this.parent = parentBehavior;
//~ };

gdjs.ParentingRuntimeBehavior.prototype._update = function(forceUpdate = false){
	
	//~ if(this.owner.id === 2 && this._frame % 60 === 0){
		//~ console.log("_update", this.transform);
	//~ }
	if(this.owner.id === 2 && this._frame < 10){
		console.log("_update", this.transform);
	}
	
	//~ if(!this._updatedThisFrame || forceUpdate){

		if(this.parent){
			this.parent._update(forceUpdate);
		}

		if(this.owner.getX() + this.owner.getCenterX() !== this.x){
			this.x = this.owner.getX() + this.owner.getCenterX();
			this._updateTransform = true;
		}
		if(this.owner.getY() + this.owner.getCenterY() !== this.y){
			this.y = this.owner.getY() + this.owner.getCenterY();
			this._updateTransform = true;
		}
		if(this.owner.getAngle() !== this.rot){
			this.rot = this.owner.getAngle();
			this._updateTransform = true;
		}
		if(this.owner.getScaleX && (this.owner.getScaleX() !== this.sx)){
			console.log("new scale x: ", this.owner.getScaleX());
			this.sx = this.owner.getScaleX();
			this._updateTransform = true;
		}
		if(this.owner.getScaleY && (this.owner.getScaleY() !== this.sy)){
			this.sy = this.owner.getScaleY();
			this._updateTransform = true;
		}

		if(this._updateTransform || this._updateWorldTransform){
			
			if(this.owner.id === 2 && this._frame % 60 === 0){
				console.log("    update a transform");
			}

			if(this._updateTransform){
				this.transform.set(this.x, this.y, this.rot, this.sx, this.sy);
				
				if(this.owner.id === 2 && this._frame % 60 === 0){
					console.log("        update local transform", this.x, this.y, this.rot, this.sx, this.sy);
				}
			}

			if(this.parent){
				this.worldTransform = this.parent.worldTransform.cloneMul(this.transform);
				
				if(this.owner.id === 2 && this._frame % 60 === 0){
					console.log("        update world transform");
				}
				
			}
			else{
				this.worldTransform = this.transform.clone();
			}

			for(var i=0; i<this.children.length; i++){
				//~ console.log(this.children[i].owner.id);
				this.children[i]._updateWorldTransform = true;
			}
		}

		this._updateTransform = false;
		this._updateWorldTransform = false;
	//~ }
	
	this._frame += 1;

	this._updatedThisFrame = true;
};

gdjs.ParentingRuntimeBehavior.prototype._setOwnerWorldTransform = function()
{
	
	if(this.owner.id === 2 && this._frame < 10){
		console.log("decompose: ", this.worldTransform, this.worldTransform.decompose());
	}
	
	var transformData = this.worldTransform.decompose();
	this.owner.setX(transformData.x - this.owner.getCenterX());
	this.owner.setY(transformData.y - this.owner.getCenterY());
	this.owner.setAngle(transformData.rot);
	if(this.owner.setScaleX){
		this.owner.setScaleX(transformData.sx);
	}
	if(this.owner.setScaleY){
		this.owner.setScaleY(transformData.sy);
	}
};

gdjs.ParentingRuntimeBehavior.prototype._setOwnerLocalTransform = function()
{
	if(this._firstTime){
		this._update(true);
		this._firstTime = false;
	}
	
	this.owner.setX(this.x - this.owner.getCenterX());
	this.owner.setY(this.y - this.owner.getCenterY());
	this.owner.setAngle(this.rot);
	if(this.owner.setScaleX){
		this.owner.setScaleX(this.sx);
	}
	if(this.owner.setScaleY){
		this.owner.setScaleY(this.sy);
	}
};

gdjs.ParentingRuntimeBehavior.prototype.printData = function()
{
	parent_id = this.parent !== null ? this.parent.owner.id : null;
	children_id = [];
	for(var i=0; i<this.children.length; i++){
		children_id.push(this.children[i].owner.id);
	}
	console.log("This: ", this.owner.id, "Parent: ", parent_id, "\n", "Children: ", children_id);
};

gdjs.ParentingRuntimeBehavior.prototype.doStepPreEvents = function(runtimeScene)
{
	this._updatedThisFrame = false;
	
	this._setOwnerLocalTransform();
};

gdjs.ParentingRuntimeBehavior.prototype.doStepPostEvents = function(runtimeScene)
{
	this._update();

	this._setOwnerWorldTransform();
};

gdjs.ParentingRuntimeBehavior.prototype.onDeActivate = function()
{
	if(this.parent){
		this.parent._removeChildBehavior(this, true);
	}

	for(var i=0; i<this.children.length; i++){
		this._removeChildBehavior(this.children[i], true);
	}
}
