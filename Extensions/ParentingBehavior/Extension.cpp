/**

GDevelop - ParentingBehavior Extension
Copyright (c) 2018 Franco Maciel (francomaciel10@gmail.com)
This project is released under the MIT License.
*/

#include "GDCpp/Extensions/ExtensionBase.h"
#include "GDCpp/Runtime/Project/BehaviorsSharedData.h"

#include "ParentingBehavior.h"


void DeclareParentingBehaviorExtension(gd::PlatformExtension & extension)
{
    extension.SetExtensionInformation("ParentingBehavior",
                          _("Parenting Behavior"),
                          _("This extension can emulate a parent-child system."),
                          "Franco Maciel",
                          "Open source (MIT License)");

    gd::BehaviorMetadata & aut = extension.AddBehavior("Parenting",
              _("Parentable object"),
              _("Parenting"),
              _("Objects that can follow their parents transformations."),
              "",
              "CppPlatform/Extensions/AStaricon.png",
              "ParentingBehavior",
              std::make_shared<ParentingBehavior>(),
              std::make_shared<gd::BehaviorsSharedData>());

    #if defined(GD_IDE_ONLY)
    aut.SetIncludeFile("ParentingBehavior/ParentingBehavior.h");

    aut.AddAction("AddChild",
                   _("Add child"),
                   _("Make an object to be a child of another."),
                   _("Add _PARAM2_ to _PARAM0_ children"),
                   _(""),
                   "CppPlatform/Extensions/LinkedObjectsicon24.png",
                   "CppPlatform/Extensions/LinkedObjectsicon16.png")
        .AddParameter("object", _("Parent"))
        .AddParameter("behavior", _("Behavior"), "Parenting")
        .AddParameter("objectPtr", _("Child"))
        .AddParameter("yesorno", _("Keep Global Transform?"), "", true).SetDefaultValue("yes")
        .SetFunctionName("AddChild").SetIncludeFile("ParentingBehavior/ParentingBehavior.h");

    aut.AddAction("RemoveChild",
                   _("Remove child"),
                   _("Delete the relation between a child and a parent."),
                   _("Remove _PARAM2_ to _PARAM0_ children"),
                   _(""),
                   "CppPlatform/Extensions/LinkedObjectsicon24.png",
                   "CppPlatform/Extensions/LinkedObjectsicon16.png")
        .AddParameter("object", _("Parent"))
        .AddParameter("behavior", _("Behavior"), "Parenting")
        .AddParameter("objectPtr", _("Child"))
        .AddParameter("yesorno", _("Keep Global Transform?"), "", true).SetDefaultValue("yes")
        .SetFunctionName("RemoveChild").SetIncludeFile("ParentingBehavior/ParentingBehavior.h");




    aut.AddAction("PrintData",
                   _("Print data"),
                   _("Display behavior data in the console."),
                   _("Print _PARAM0_ data"),
                   _(""),
                   "CppPlatform/Extensions/LinkedObjectsicon24.png",
                   "CppPlatform/Extensions/LinkedObjectsicon16.png")
        .AddParameter("object", _("Parent"))
        .AddParameter("behavior", _("Behavior"), "Parenting")
        .SetFunctionName("PrintData").SetIncludeFile("ParentingBehavior/ParentingBehavior.h");

    #endif

}

/**
 * \brief This class declares information about the extension.
 */
class ParentingBehaviorCppExtension : public ExtensionBase
{
public:

    /**
     * Constructor of an extension declares everything the extension contains: objects, actions, conditions and expressions.
     */
    ParentingBehaviorCppExtension()
    {
        DeclareParentingBehaviorExtension(*this);
        GD_COMPLETE_EXTENSION_COMPILATION_INFORMATION();
    };

};

#if defined(ANDROID)
extern "C" ExtensionBase * CreateGDCppParentingBehaviorExtension() {
    return new ParentingBehaviorCppExtension;
}
#elif !defined(EMSCRIPTEN)
/**
 * Used by GDevelop to create the extension class
 * -- Do not need to be modified. --
 */
extern "C" ExtensionBase * GD_EXTENSION_API CreateGDExtension() {
    return new ParentingBehaviorCppExtension;
}
#endif


// class Extension : public ExtensionBase
// {
// public:

//     /**
//      * Constructor of an extension declares everything the extension contains: objects, actions, conditions and expressions.
//      */
//     Extension()
//     {
//         SetExtensionInformation("ParentingBehavior",
//                               _("Parenting Behavior"),
//                               _("This extension can emulate a parent-child system."),
//                               "Franco Maciel",
//                               "Open source (MIT License)");

//         {
//             gd::BehaviorMetadata & aut = AddBehavior("ParentingBehavior",
//                   _("Parenting"),
//                   "Parenting",
//                   _("With this, characters will move while avoiding all objects that are flagged as obstacles."),
//                   "",
//                   "CppPlatform/Extensions/AStaricon.png",
//                   "ParentingBehavior",
//                   std::make_shared<ParentingBehavior>(),
//                   std::make_shared<gd::BehaviorsSharedData>());

//             #if defined(GD_IDE_ONLY)

//             aut.SetIncludeFile("ParentingBehavior/ParentingBehavior.h");

//             aut.AddAction("AddChild",
//                        _("Add child"),
//                        _("Make an object to be a child of another."),
//                        _("Add _PARAM2_ to _PARAM0_ children"),
//                        _("Parenting"),
//                        "CppPlatform/Extensions/LinkedObjectsicon24.png",
//                        "CppPlatform/Extensions/LinkedObjectsicon16.png")
//                 .AddParameter("object", _("Parent"))
//                 .AddParameter("behavior", _("Behavior"), "ParentingBehavior")
//                 .AddParameter("objectPtr", _("Child"))
//                 .SetFunctionName("AddChild").SetIncludeFile("ParentingBehavior/ParentingBehavior.h");

//             aut.AddAction("PrintData",
//                            _("Print data"),
//                            _("Display behavior data in the console."),
//                            _("Print _PARAM0_ data"),
//                            _("Parenting"),
//                            "CppPlatform/Extensions/LinkedObjectsicon24.png",
//                            "CppPlatform/Extensions/LinkedObjectsicon16.png")
//                 .AddParameter("object", _("Parent"))
//                 .AddParameter("behavior", _("Behavior"), "ParentingBehavior")
//                 .SetFunctionName("PrintData").SetIncludeFile("ParentingBehavior/ParentingBehavior.h");

//             #endif
//         }

//         GD_COMPLETE_EXTENSION_COMPILATION_INFORMATION();
//     };
// };

// /**
//  * Used by GDevelop to create the extension class
//  * -- Do not need to be modified. --
//  */
// extern "C" ExtensionBase * GD_EXTENSION_API CreateGDExtension() {
//     return new Extension;
// }
