// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once 

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "FPSHUD.generated.h"

UCLASS()
class AFPSHUD : public AHUD
{
	GENERATED_BODY()

public:
	AFPSHUD();
    
	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;
    
    virtual void BeginPlay() override;
    
    virtual void Tick(float InDeltaTime) override;
    
protected:
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ProgressBar")
    TSubclassOf<class UMainMenuWD> ProgressBarClass;
    
    UPROPERTY(BlueprintReadOnly, Category = "ProgressBar")
    class UMainMenuWD* ProgressBar;
    
private:
	/** Crosshair asset pointer */
	class UTexture2D* CrosshairTex;

};

