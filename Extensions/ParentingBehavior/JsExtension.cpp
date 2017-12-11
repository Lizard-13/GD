/**

GDevelop - ParentingBehavior Extension
Copyright (c) 2018 Franco Maciel (francomaciel10@gmail.com)
This project is released under the MIT License.
*/

#if defined(GD_IDE_ONLY)
#include "GDCore/Extensions/PlatformExtension.h"
#include "GDCore/Tools/Localization.h"

#include <iostream>

void DeclareParentingBehaviorExtension(gd::PlatformExtension & extension);

/**
 * \brief This class declares information about the JS extension.
 */
class ParentingBehaviorJsExtension : public gd::PlatformExtension
{
public:

    /**
     * \brief Constructor of an extension declares everything the extension contains: objects, actions, conditions and expressions.
     */
    ParentingBehaviorJsExtension()
    {
        SetExtensionInformation("ParentingBehavior",
                          _("Parenting Behavior"),
                          _("This extension can emulate a parent-child system."),
                          "Franco Maciel",
                          "Open source (MIT License)");
        DeclareParentingBehaviorExtension(*this);

        GetBehaviorMetadata("ParentingBehavior::Parenting")
            .SetIncludeFile("Extensions/ParentingBehavior/parentingruntimebehavior.js")
            .AddIncludeFile("Extensions/ParentingBehavior/transform.js");

        std::map<gd::String, gd::InstructionMetadata > & autActions = GetAllActionsForBehavior("ParentingBehavior::Parenting");
        // std::map<gd::String, gd::InstructionMetadata > & autConditions = GetAllConditionsForBehavior("ParentingBehavior::Parenting");
        // std::map<gd::String, gd::ExpressionMetadata > & autExpressions = GetAllExpressionsForBehavior("ParentingBehavior::Parenting");
            
        autActions["ParentingBehavior::AddChild"].SetFunctionName("addChild");
        autActions["ParentingBehavior::PrintData"].SetFunctionName("printData");

        StripUnimplementedInstructionsAndExpressions();
        GD_COMPLETE_EXTENSION_COMPILATION_INFORMATION();
    };
};

#if defined(EMSCRIPTEN)
extern "C" gd::PlatformExtension * CreateGDJSParentingBehaviorExtension() {
    return new ParentingBehaviorJsExtension;
}
#else
/**
 * Used by GDevelop to create the extension class
 * -- Do not need to be modified. --
 */
extern "C" gd::PlatformExtension * GD_EXTENSION_API CreateGDJSExtension() {
    return new ParentingBehaviorJsExtension;
}
#endif
#endif
