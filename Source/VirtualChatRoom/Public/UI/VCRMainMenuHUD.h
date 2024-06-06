// This project is made for a test assignment

#pragma once

#include "CoreMinimal.h"
#include "UI/VCRBaseHUD.h"
#include "VCRMainMenuHUD.generated.h"

UCLASS()
class VIRTUALCHATROOM_API AVCRMainMenuHUD : public AVCRBaseHUD
{
    GENERATED_BODY()

public:
    AVCRMainMenuHUD();

    virtual void BeginPlay() override;

protected:
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI")
    TSubclassOf<UUserWidget> SetNickNameWidgetClass;
};
