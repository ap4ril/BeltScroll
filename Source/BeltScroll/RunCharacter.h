// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "RunCharacter.generated.h"

UCLASS()
class BELTSCROLL_API ARunCharacter : public ACharacter
{
	GENERATED_BODY()

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"));
	class USpringArmComponent* CameraArm;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"));
	class UCameraComponent* Camera;

public:
	UFUNCTION(BlueprintImplementableEvent, Category = "Lane")
		void ChangeLane1();

	UFUNCTION(BlueprintCallable, Category = "Lane")
		void ChangeLaneUpdate1(float Value);

	UFUNCTION(BlueprintCallable, Category = "Lane")
		void ChangeLaneFinished1();




	// Sets default values for this character's properties
	ARunCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
		void MoveLeft();
	UFUNCTION()
		void MoveRight();
	UFUNCTION()
		void MoveDown();

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};