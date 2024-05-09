knowledge_base = {
    "cold" : [
        "1: Tylenol",
        "2: Panadol",
        "3: Nasal spray",
        "4: Please wear warm clothes!"
    ],

    "influenza": [
        "1: Tamiflu",
        "2: Panadol",
        "3: Zanamivir",
        "4: Please take a warm bath and do salt gargling!"
    ],

    "typhoid": [
        "1: Chloramphenicol",
        "2: Amoxicillin",
        "3: Ciproflaxacin",
        "4: Azithromycin",
        "5: Please do complete bed rest and take a soft diet!"
    ],

    "chicken pox" : [
        "1: Varicella vaccine",
        "2: Immunoglobulin",
        "3: Acetomenaphin",
        "4: Acyclovir",
        "5: Please have oatmeal and stay at home!"
    ],

    "measles" : [
        "1: Tylenol",
        "2: Aleve",
        "3: Advil",
        "4: Vitamin A",
        "5: Please get rest and use more liquid!"
    ],

    "malaria" : [
        "1: Aralen",
        "2: Qualaquin",
        "3: Plaquenil",
        "4: Mefloquine",
        "5: Please do not sleep in the open air and cover your full skin!"
    ]
}

def respond(symptoms):
    if len(symptoms) == 3:
        if "rash" in symptoms and "body ache" in symptoms and "fever" in symptoms:
            print("You have chicken pox!")
            print("Please take the following medicines and precautions:")
            for i in knowledge_base["chicken pox"]:
                print(i)
        else:
            print("Question is not present in the knowledge base!")
            # You can prompt for adding the answer here if needed.
    elif len(symptoms) == 4:
        if "headache" in symptoms and "runny nose" in symptoms and "sneezing" in symptoms and "sore throat" in symptoms:
            print("You have cold!")
            print("Please take the following medicines and precautions:")
            for i in knowledge_base["cold"]:
                print(i)
        # Add other conditions for different diseases
    # Add conditions for other lengths of symptoms list

if __name__ == "__main__":
    print("Welcome to the Medical Diagnosis Expert System!")
    print("Please enter your symptoms separated by commas (e.g., headache,runny nose,fever):")
    symptoms_input = input().split(',')
    respond(symptoms_input)