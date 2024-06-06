// This project is made for a test assignment

#pragma once

#include "CoreMinimal.h"
#include "UI/Widgets/VCRBaseWidget.h"
#include "VCRPlayersListWidget.generated.h"

class UScrollBox;

UCLASS()
class VIRTUALCHATROOM_API UVCRPlayersListWidget : public UVCRBaseWidget
{
    GENERATED_BODY()

protected:
    UVCRPlayersListWidget();

    virtual void NativeOnInitialized() override;

    void ChangeVisibility(bool WidgetIsVisibile);

    TArray<FString> GetPlayersNames() const;

    UPROPERTY(meta = (BindWidget))
    UScrollBox* PlayersListBox;

    UPROPERTY()
    TSubclassOf<UUserWidget> PlayerNameTextWidgetClass;
};
