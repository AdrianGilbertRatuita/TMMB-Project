// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class TMMB_PROJECTEditorTarget : TargetRules
{
	public TMMB_PROJECTEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;

		ExtraModuleNames.AddRange( new string[] { "TMMB_PROJECT" } );
	}
}
