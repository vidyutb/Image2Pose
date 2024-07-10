// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Animation/PoseAsset.h"
#include "Engine/SkeletalMesh.h"
#include "AssetToolsModule.h"
#include "AssetRegistry/AssetRegistryModule.h"
#include "Image2PoseFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class IMAGE2POSE_API UImage2PoseFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	

	UFUNCTION(BlueprintCallable, Category="Image2Pose Helpers")
	void GeneratePoseAsset(UObject* InParent, USkeletalMeshComponent* SkeletalMesh, FString AssetName, FString AssetPath);
	
	
	
};
