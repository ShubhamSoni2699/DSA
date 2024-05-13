#include <cmath>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

void getMinimumError(double error, vector<int> &widths,
                     unordered_map<int, vector<double>> &widthMap,
                     double &currentMini, double &totalMini, int &size,
                     int currNo, unordered_map<int, int> &noOfPieces,
                     unordered_map<int, int> copyNoOfPieces,
                     unordered_map<int, pair<int, int>> &choiceOfPieces) {
  if (currNo == size - 1) {
    copyNoOfPieces[widths[currNo]] = error >= 0
                                         ? choiceOfPieces[widths[currNo]].second
                                         : choiceOfPieces[widths[currNo]].first;
    currentMini += error;
    if (abs(currentMini) < abs(totalMini)) {
      noOfPieces = copyNoOfPieces;
      totalMini = currentMini;
    }
    return;
  }
  double Aerr = currentMini + error;

  copyNoOfPieces[widths[currNo]] = error >= 0
                                       ? choiceOfPieces[widths[currNo]].second
                                       : choiceOfPieces[widths[currNo]].first;
  getMinimumError(widthMap[widths[currNo + 1]][0], widths, widthMap, Aerr,
                  totalMini, size, currNo + 1, noOfPieces, copyNoOfPieces,
                  choiceOfPieces);
  getMinimumError(widthMap[widths[currNo + 1]][1], widths, widthMap, Aerr,
                  totalMini, size, currNo + 1, noOfPieces, copyNoOfPieces,
                  choiceOfPieces);
}

int main() {
  double thickness = 0.00;
  int noOfWidths = 0;
  int packetSize = 0;
  int stepSize = 0;

  cout << "Enter thickness value :-";
  cin >> thickness;
  cout << endl;
  cout << "Enter no of diffrent widths :-";
  cin >> noOfWidths;
  cout << endl;
  cout << "Enter packetSize and stepSize :-";
  cin >> packetSize >> stepSize;
  cout << endl;

  unordered_map<int, vector<double>> widthMap;
  unordered_map<int, pair<int, int>> choiceOfPieces;
  vector<int> widths;

  for (int i = 0; i < noOfWidths; i++) {
    cout << "Input value for width and stack height :-";
    int width = 0;
    double stackHeight = 0.00;
    cin >> width >> stackHeight;
    cout << endl;

    double noOfPieces = stackHeight / (thickness * packetSize * stepSize);

    choiceOfPieces[width] =
        make_pair(floor(noOfPieces) * packetSize * stepSize,
                  (floor(noOfPieces) + 1) * packetSize * stepSize);

    widthMap[width].push_back(floor(noOfPieces) - noOfPieces);
    widthMap[width].push_back(floor(noOfPieces) + 1 - noOfPieces);

    widths.push_back(width);
  }

  for (auto i : choiceOfPieces) {
    cout << i.first << "-->" << i.second.first << "& " << i.second.second
         << endl;
  }

  cout << endl << endl;

  for (auto i : widthMap) {
    cout << i.first << " :->  " << i.second[0] << " ," << i.second[1] << endl;
  }

  double currentMini = 0.00;
  double totalMini = 1000.00;

  unordered_map<int, int> noOfPieces;
  unordered_map<int, int> copyNoOfPieces;

  for (auto i : widths) {
    noOfPieces[i] = -1;
    copyNoOfPieces[i] = -1;
  }

  getMinimumError(widthMap[widths[0]][0], widths, widthMap, currentMini,
                  totalMini, noOfWidths, 0, noOfPieces, copyNoOfPieces,
                  choiceOfPieces);
  cout << endl;
  getMinimumError(widthMap[widths[0]][1], widths, widthMap, currentMini,
                  totalMini, noOfWidths, 0, noOfPieces, copyNoOfPieces,
                  choiceOfPieces);
  cout << endl << endl;
  
  for (auto i : noOfPieces) {
    cout << i.first << "-->  " << i.second << endl;
  }
  cout << endl;
  
  cout <<"Total Mini :->  "<< totalMini << endl;
  cout <<"Total Diffrence in Pieces :->  "<< (totalMini*packetSize)*stepSize << endl;

  return 0;
}