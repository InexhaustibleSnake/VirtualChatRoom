// This project is made for a test assignment

#include "UI/VCRChatRoomHUD.h"
#include "UI/Widgets/InGame/VCRInGameHUDWidget.h"
#include "Blueprint/UserWidget.h"

AVCRChatRoomHUD::AVCRChatRoomHUD()
{
    static ConstructorHelpers::FClassFinder<UUserWidget> FoundGameWidgetClass(TEXT("/Game/UI/InGame/WBP_InGameHUD"));

    InGameWidgetClass = FoundGameWidgetClass.Class;
}

void AVCRChatRoomHUD::BeginPlay()
{
    Super::BeginPlay();

    const auto CreatedInGameWidget = CreateWidget<UUserWidget>(GetWorld(), InGameWidgetClass);
    if (CreatedInGameWidget)
    {
        CreatedInGameWidget->AddToViewport();
        InGameWidget = CreatedInGameWidget;
    }
}
