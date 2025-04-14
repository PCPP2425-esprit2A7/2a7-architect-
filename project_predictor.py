from sklearn.feature_extraction.text import TfidfVectorizer
from sklearn.ensemble import RandomForestRegressor
import numpy as np

def train_model(descriptions, durations):
    """
    Entraîne le modèle avec les descriptions de projets et leurs durées
    """
    # Créer et entraîner le vectorizer
    vectorizer = TfidfVectorizer(max_features=100, stop_words='english')
    X = vectorizer.fit_transform(descriptions)
    
    # Créer et entraîner le modèle
    model = RandomForestRegressor(n_estimators=100, random_state=42)
    model.fit(X, durations)
    
    return model, vectorizer

def text_to_features(text, vectorizer):
    """
    Convertit un texte en features numériques
    """
    return vectorizer.transform([text])

def predict_duration(features, model, vectorizer):
    """
    Prédit la durée d'un projet
    """
    prediction = model.predict(features)
    return int(round(prediction[0]))
