// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PlayerStateInput.h"
#include "PhysicsPublic.h"
#include "PlayerStateMachine.generated.h"

class State;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class IGNITIONRUSH_API UPlayerStateMachine : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPlayerStateMachine();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	TMap<FString, State*> stateMap;

	State* currentState;
	PlayerStateInput* stateInput;

	bool stateChanged = false;

	void InitStateMap();
	void SetInitialState();
	void ChangeState(FString stateName);


	// Event called every physics tick and sub-step.
	UFUNCTION(BlueprintNativeEvent)
		void PhysicsTick(float SubstepDeltaTime);
	virtual void PhysicsTick_Implementation(float SubstepDeltaTime); //if blueprint doesn't use the PhysicsTick above, the one on this line will be used.

	//Custom physics Delegate
	FCalculateCustomPhysics OnCalculateCustomPhysics;
	void CustomPhysics(float DeltaTime, FBodyInstance* BodyInstance);


public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
