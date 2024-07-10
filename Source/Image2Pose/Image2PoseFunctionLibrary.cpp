// Fill out your copyright notice in the Description page of Project Settings.


#include "Image2PoseFunctionLibrary.h"
#include "UObject/SavePackage.h"


void UImage2PoseFunctionLibrary::GeneratePoseAsset(UObject* InParent, USkeletalMeshComponent* SkeletalMesh, FString AssetName, FString AssetPath) {
    FAssetToolsModule& AssetToolsModule = FModuleManager::GetModuleChecked<FAssetToolsModule>("AssetTools");
    IAssetTools& AssetTools = AssetToolsModule.Get();

    FString PackageName = TEXT("/Game/Image2Pose_PoseAssets/") + AssetName;

    // Create the new PoseAsset
    UPoseAsset* PoseAsset = Cast<UPoseAsset>(AssetTools.CreateAsset(AssetName, FPackageName::GetLongPackagePath(PackageName), UPoseAsset::StaticClass(), nullptr));

    if (PoseAsset)
    {
        // Initialize the PoseAsset with the given skeletal mesh
        PoseAsset->AddOrUpdatePose(FName(*AssetName), SkeletalMesh, true);

        // Notify the asset registry
        FAssetRegistryModule::AssetCreated(PoseAsset);
        PoseAsset->MarkPackageDirty();

        // Optionally save the asset
        FString PackageFileName = FPackageName::LongPackageNameToFilename(PackageName, FPackageName::GetAssetPackageExtension());
        UPackage* Package = PoseAsset->GetOutermost();
        FSavePackageArgs SaveArgs;
        SaveArgs.TopLevelFlags = RF_Public | RF_Standalone;
        SaveArgs.SaveFlags = SAVE_None;
        SaveArgs.bForceByteSwapping = false;
        SaveArgs.bWarnOfLongFilename = false;

        UPackage::Save(Package, PoseAsset, *PackageFileName, SaveArgs);
    }
    return;
}