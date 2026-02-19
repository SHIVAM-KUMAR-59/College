from groq import Groq
import PyPDF2
import os

client = Groq(api_key=os.getenv("GROQ_API_KEY"))

def extract_text_from_pdf(pdf_path):
    text = ""
    with open(pdf_path, "rb") as file:
        reader = PyPDF2.PdfReader(file)
        for page in reader.pages:
            extracted = page.extract_text()
            if extracted:
                text += extracted + "\n"
    return text


def solve_crime_rag(pdf_path, query):
    document_text = extract_text_from_pdf(pdf_path)

    prompt = f"""
    You are a crime investigation assistant.

    Use the following crime report to answer the question.

    Crime Report:
    {document_text}

    Question:
    {query}

    Answer clearly and based only on the report.
    """

    response = client.chat.completions.create(
        model="llama-3.1-8b-instant",
        messages=[
            {"role": "system", "content": "You are a helpful crime investigation assistant."},
            {"role": "user", "content": prompt}
        ],
        temperature=0
    )

    return response.choices[0].message.content


questions = [
    "What distinguishing physical features were reported by witnesses about the suspects?",
    "What is the connection between Sophia Reynolds and the crime scene?",
    "What ballistic evidence was recovered from the abandoned vehicle?",
    "How much of the stolen property remains unrecovered?",
    "What international coordination has been initiated regarding this case?"
]

pdf_path = r"/Users/shivamkumar/Desktop/College/3rd Year/6th Semester/AI Lab/Day-09/case_brief.pdf"

for i, question in enumerate(questions, 1):
    print(f"\nQuestion {i}: {question}")
    answer = solve_crime_rag(pdf_path, question)
    print(f"Answer {i}: {answer}")
    print("-" * 80)
