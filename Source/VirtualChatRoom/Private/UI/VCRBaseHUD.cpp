// This project is made for a test assignment

#include "UI/VCRBaseHUD.h"
#include "UI/Widgets/VCRBaseWidget.h"

void AVCRBaseHUD::BeginPlay() 
{
	Super::BeginPlay();

	CreateInGameWidget();
}

void AVCRBaseHUD::CreateInGameWidget() 
{
    const auto CreatedWidget = CreateWidget<UVCRBaseWidget>(GetWorld(), InGameWidget);
	if (!CreatedWidget) return;

	CreatedWidget->AddToViewport();
}
