// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;

public class MyProjectCodeReport : ModuleRules
{
	public MyProjectCodeReport(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicIncludePaths.AddRange(
            new string[] {
				// ... add public include paths required here ...
                "DelegateHandler"
            }
            );

        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore",
            //for net work
            "Sockets","Networking",
            //for my EventHandler
            "DelegateHandler"
        });

		PrivateDependencyModuleNames.AddRange(new string[] {
            //"DelegateHandler"
        });

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });
		
		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
