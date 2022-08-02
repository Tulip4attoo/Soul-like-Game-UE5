// Copyright (c) 2022 Michal Smoleň 

#pragma once

#include "CoreMinimal.h"
#include "IDetailCustomization.h"

/**
 * 
 */
class NIAGARAUIRENDEREREDITOR_API FNiagaraWidgetDetailCustomization : public IDetailCustomization
{
public:
	virtual void CustomizeDetails(IDetailLayoutBuilder& DetailBuilder) override;
	virtual void CustomizeDetails(const TSharedPtr<IDetailLayoutBuilder>& DetailBuilder) override;

	static TSharedRef<IDetailCustomization> MakeInstance();

private:
	void RegisterPropertyChanged(IDetailLayoutBuilder& DetailBuilder);

	void RegisterPropertyChangedFullRefresh(IDetailLayoutBuilder& DetailBuilder, const FName Property, bool RegisterChildProperty = false);

	void CheckWarnings();
	
	void DisplayWarningBox(IDetailLayoutBuilder& DetailBuilder);

	void OnIgnoreWarningsPressed();

	void OnAutoPopulatePressed();

	void OnNiagaraSystemChanged(class UNiagaraSystem* System);

	void ForceRefreshDetailPanel();

	void AddWarning(FString WarningMessage);

	FText BuildWarningMessage();

private:
	TWeakObjectPtr<class UNiagaraSystemWidget> CachedNiagaraWidget;
	TWeakPtr<IDetailLayoutBuilder> CachedDetailBuilder;

	TArray<FString> WarningMessages;

	bool ShowAutoPopulate = false;
};
