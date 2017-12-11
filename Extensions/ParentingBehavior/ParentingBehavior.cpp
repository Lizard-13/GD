/**

GDevelop - ParentingBehavior Extension
Copyright (c) 2018 Franco Maciel (francomaciel10@gmail.com)
This project is released under the MIT License.
*/

#include "ParentingBehavior.h"
#include "GDCpp/Runtime/RuntimeScene.h"
#include <iostream>

ParentingBehavior::ParentingBehavior()
{

}

ParentingBehavior::~ParentingBehavior()
{

}

void ParentingBehavior::AddChild(RuntimeObject* child, bool keepGlobalTransform)
{
    std::cout << "AddChild" << std::endl;
}

void ParentingBehavior::RemoveChild(RuntimeObject* child, bool keepGlobalTransform)
{
    std::cout << "RemoveChild" << std::endl;
}

void ParentingBehavior::Reparent(RuntimeObject* parent)
{
    std::cout << "RemoveChild" << std::endl;
}

void ParentingBehavior::PrintData()
{
    std::cout << "PrintData" << std::endl;
}


void ParentingBehavior::DoStepPreEvents(RuntimeScene & scene)
{

}

void ParentingBehavior::DoStepPostEvents(RuntimeScene & scene)
{

}
