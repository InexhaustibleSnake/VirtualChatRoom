// This project is made for a test assignment

#include "UI/VCRMainMenuHUD.h"
#include "Blueprint/UserWidget.h"

AVCRMainMenuHUD::AVCRMainMenuHUD()
{
    static ConstructorHelpers::FClassFinder<UUserWidget> FoundGameWidgetClass(TEXT("/Game/UI/MainMenu/WBP_MainMenu"));

    InGameWidgetClass = FoundGameWidgetClass.Class;
}

