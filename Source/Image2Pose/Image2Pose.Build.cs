// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Image2Pose : ModuleRules
{
	public Image2Pose(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
            "Core",
            "CoreUObject",
            "Engine",
            "InputCore",
			"EnhancedInput",
            "AssetRegistry",
			"AssetTools",
			"EditorScriptingUtilities"
        });
	}
}
