// This project is made for a test assignment

#include "UI/VCRMainMenuHUD.h"
#include "Blueprint/UserWidget.h"
#include "UI/Widgets/MainMenu/VCRSetPlayerNameWidget.h"

AVCRMainMenuHUD::AVCRMainMenuHUD()
{
    static ConstructorHelpers::FClassFinder<UUserWidget> FoundGameWidgetClass(TEXT("/Game/UI/MainMenu/WBP_MainMenu"));

    InGameWidgetClass = FoundGameWidgetClass.Class;

    static ConstructorHelpers::FClassFinder<UUserWidget> FoundSetNickNameWidgetClass(TEXT("/Game/UI/MainMenu/WBP_SetPlayerName"));

    SetNickNameWidgetClass = FoundSetNickNameWidgetClass.Class;
}

void AVCRMainMenuHUD::BeginPlay()
{
    Super::BeginPlay();

    const auto SetPlayerNameWidget = CreateWidget<UVCRSetPlayerNameWidget>(InGameWidget, SetNickNameWidgetClass);
    if (!SetPlayerNameWidget) return;

    SetPlayerNameWidget->AddToViewport();
}
