import React from 'react'
import HistoryCards from '../Components/HistoryCards'
import { marked } from 'marked'
import { Button } from '@mui/material';

const str="Here are a few examples of matrix math operations:\n\n**Matrix Addition**\n\nLet's say we have two 2x2 matrices:\n\nA = | 1  2 |\n    | 3  4 |\n\nB = | 5  6 |\n    | 7  8 |\n\nTo add these matrices, we add corresponding elements:\n\nA + B = | 1+5  2+6 |  = | 6  8 |\n         | 3+7  4+8 |       | 10 12 |\n\n**Matrix Multiplication**\n\nLet's say we have two 2x2 matrices:\n\nA = | 2  -3 |\n    | 1   1 |\n\nB = | 4   1 |\n    | -2  2 |\n\nTo multiply these matrices, we calculate each element as follows:\n\nA11 = (2)(4) + (-3)(-2) = 8 + 6 = 14\nA12 = (2)(1) + (-3)(2) = 2 - 6 = -4\nA21 = (1)(4) + (1)(-2) = 4 - 2 = 2\nA22 = (1)(1) + (1)(2) = 1 + 2 = 3\n\nSo the product matrix is:\n\nA * B = | 14 -4 |\n          | 2   3 |\n\n**Matrix Transpose**\n\nLet's say we have a 2x2 matrix:\n\nA = | 1  2 |\n    | 3  4 |\n\nThe transpose of A, denoted by A^T or A', is:\n\nA^T = | 1  3 |\n        | 2  4 |\n\n**Determinant**\n\nThe determinant of a 2x2 matrix:\n\nA = | a  b |\n    | c  d |\n\nis calculated as:\n\ndet(A) = ad - bc\n\nFor example, if A = | 2  3 |\n                   | 4  5 |,\n\nthen det(A) = (2)(5) - (3)(4) = 10 - 12 = -2.\n\n**Inverse**\n\nThe inverse of a 2x2 matrix A:\n\nA = | a  b |\n    | c  d |\n\nis calculated as:\n\nA^-1 = (1 / det(A)) * | d  -b |\n                            | -c  a |\n\nFor example, if A = | 2  3 |\n                   | 4  5 | and det(A) = -2,\n\nthen A^-1 = (1 / -2) * | 5  -3 |\n                             | -4  2 |\n\n= | -5/2  3/2 |        = | 2  -3/2 |\n\n  | 2   -1 |\n\nDo you have any specific questions or operations you'd like to know about?"
async function selectFolderAndSaveFile() {
  try {
      // Open the directory picker
      const handle = await window.showDirectoryPicker();

      // Create a file in the selected folder
      const fileHandle = await handle.getFileHandle("example.md", { create: true });

      // Create a writable stream
      const writable = await fileHandle.createWritable();

      // Write data into the file
      await writable.write(marked(str));
      
      // Close the writable stream
      await writable.close();

      alert("File saved successfully!");
  } catch (error) {
      console.error("Error selecting folder or saving file:", error);
  }
}

const ExperimentPage = () => {
  console.log()
  return (
    <>
    <div>ExperimentPage
        {marked(str)}
    </div>
    <Button onClick={selectFolderAndSaveFile}>Download</Button>
    </>
  )
}

export default ExperimentPage