/**

GDevelop - ParentingBehavior Extension
Copyright (c) 2018 Franco Maciel (francomaciel10@gmail.com)
This project is released under the MIT License.
*/

#ifndef PARENTINGBEHAVIOR_H
#define PARENTINGBEHAVIOR_H
#include "GDCpp/Runtime/Project/Behavior.h"
// #include "GDCpp/Runtime/Project/Object.h"
class RuntimeScene;

/**
 * \brief Allows objects to jump and stand on platforms.
 */
class GD_EXTENSION_API ParentingBehavior : public Behavior
{
public:
    ParentingBehavior();
    virtual ~ParentingBehavior();
    virtual Behavior* Clone() const { return new ParentingBehavior(*this); }

    void AddChild(RuntimeObject* child, bool keepGlobalTransform);
    void RemoveChild(RuntimeObject* child, bool keepGlobalTransform);

    void Reparent(RuntimeObject* parent);

    void PrintData();

private:
    virtual void DoStepPreEvents(RuntimeScene & scene);
    virtual void DoStepPostEvents(RuntimeScene & scene);
};
#endif // PARENTINGBEHAVIOR_H
