// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MainMenuWD.generated.h"

/**
 * 
 */
UCLASS()
class FPS_API UMainMenuWD : public UUserWidget
{
	GENERATED_BODY()
	
protected:
    
    UPROPERTY(BlueprintReadOnly, meta=(BindWidget))
    class UProgressBar* healthBar;
    
public:
    
    void UpdateHealth(float health);
	
	
};
