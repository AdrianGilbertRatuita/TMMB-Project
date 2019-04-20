// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class TMMB_PROJECTTarget : TargetRules
{
	public TMMB_PROJECTTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;

		ExtraModuleNames.AddRange( new string[] { "TMMB_PROJECT" } );
	}
}
