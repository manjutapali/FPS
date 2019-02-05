// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "FPSHUD.h"
#include "Engine/Canvas.h"
#include "Engine/Texture2D.h"
#include "TextureResource.h"
#include "CanvasItem.h"
#include "UI/MainMenuWD.h"
#include "UObject/ConstructorHelpers.h"

AFPSHUD::AFPSHUD()
{
	// Set the crosshair texture
	static ConstructorHelpers::FObjectFinder<UTexture2D> CrosshairTexObj(TEXT("/Game/FirstPerson/Textures/FirstPersonCrosshair"));
	CrosshairTex = CrosshairTexObj.Object;
}

void AFPSHUD::BeginPlay()
{
    Super::BeginPlay();
    
    if(APlayerController *PC = Cast<APlayerController>(PlayerOwner))
    {
        UE_LOG(LogTemp, Log, TEXT("Got Player controller reference"))
        // UE_LOG(LogTemp, Log, TEXT("Progress bar class %s"), ProgressBarClass->GetDefaultObjectName())
        if(ProgressBarClass)
        {
            UE_LOG(LogTemp, Log, TEXT("Adding progress bar to the view port"))
            ProgressBar = CreateWidget<UMainMenuWD>(PC, ProgressBarClass);
            ProgressBar->UpdateHealth(80);
            ProgressBar->AddToViewport();
            ProgressBar->SetVisibility(ESlateVisibility::Visible);
        }
    }
}

void AFPSHUD::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void AFPSHUD::DrawHUD()
{
	Super::DrawHUD();

	// Draw very simple crosshair

	// find center of the Canvas
	const FVector2D Center(Canvas->ClipX * 0.5f, Canvas->ClipY * 0.5f);

	// offset by half the texture's dimensions so that the center of the texture aligns with the center of the Canvas
	const FVector2D CrosshairDrawPosition( (Center.X),
										   (Center.Y + 20.0f));

	// draw the crosshair
	FCanvasTileItem TileItem( CrosshairDrawPosition, CrosshairTex->Resource, FLinearColor::White);
	TileItem.BlendMode = SE_BLEND_Translucent;
	Canvas->DrawItem( TileItem );
}
