# MiniProj\_PriyanshuRanjan

## Project Overview

This project focuses on real-time hand gesture recognition, integrating both static and dynamic gesture detection. It utilizes deep learning models trained on custom datasets to recognize gestures from a live feed.

## Features

- **Static Gesture Recognition**: Identifies hand gestures that do not change over time.
- **Dynamic Gesture Recognition**: Recognizes gestures involving motion using sequential data.
- **Real-time Processing**: Utilizes MediaPipe for hand tracking and runs inference on live video input.

## Dynamic gestures :<br>
1) No (moving index finger left-right)<br>
2) Wave (moving hand left-right)<br>
3) Yoyo<br>
4) Fire (make a gun with your fingers and shoot)<br>


## Static gestures:
1) Thumbs Up<br>
2) Open Palm<br>
3) Closed Palm<br>
4) Peace<br>
5) Fcuk You(middle finger)<br>
<br>

## Project Structure

```
MiniProj_PriyanshuRanjan/
├── gesture_static_model.keras      # Trained model for static gestures
├── gesture_model.keras             # Trained model for dynamic gestures
├── gesture_dataset.csv             # Dataset used for training
├── dynamic_label_encoder.npy       # Label encoder for dynamic gestures
├── static_label_encoder.npy        # Label encoder for static gestures
├── Main.ipynb                      # Jupyter notebook for real-time prediction
├── README.md                       # Project documentation
```

## Installation

### Prerequisites

Ensure you have Python installed along with the necessary dependencies:

```bash
pip install tensorflow opencv-python numpy mediapipe
```

### Clone the Repository

```bash
git clone https://github.com/itssPriiyanshu/MiniProj_PriyanshuRanjan.git
cd MiniProj_PriyanshuRanjan
```

## Usage

1. **Run the Notebook** Open `Main.ipynb` in Jupyter Notebook or Jupyter Lab and execute the "Run Live-Feed Hand Gesture Detection" cell to start real-time gesture recognition.

2. **Customising the Models**

   - Use MediaPipe to capture hand landmarks and preprocess the input for the models.
   - Run the instructed cells to add custom Static/Dynamic gestures.
   - Rebuild the model (Simply run the cells).
   - Run Live feed detection on custom dataset.

## Future Improvements

- Improve model accuracy with a larger dataset.
- More gestures can be added.
- Optimize inference for better real-time performance.

