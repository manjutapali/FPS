// Fill out your copyright notice in the Description page of Project Settings.

#include "MainMenuWD.h"
#include "Components/ProgressBar.h"


void UMainMenuWD::UpdateHealth(float health)
{
    healthBar->SetPercent(health);
}
