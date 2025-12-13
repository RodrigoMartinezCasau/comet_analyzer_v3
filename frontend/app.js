/***********************
 * FAKE RESULTS (FINAL)
 ***********************/
const fakeResults = [
  { element: "Oxygen",    wavelength: 777.1, probability: 99.6 },
  { element: "Hydrogen",  wavelength: 656.6, probability: 88.1 },
  { element: "Sodium",    wavelength: 589.9, probability: 62.7 },
  { element: "Helium",    wavelength: 587.3, probability: 92.4 },
  { element: "Carbon",    wavelength: 658.6, probability: 86.2 },
  { element: "Calcium",   wavelength: 422.9, probability: 81.0 },
  { element: "Magnesium", wavelength: 517.8, probability: 70.4 },
  { element: "Iron",      wavelength: 526.6, probability: 84.9 }
];

/***********************
 * FAKE SPECTRUM (COHERENTE)
 ***********************/
const fakeSpectrum = [
  { wavelength: 390.0, intensity: 5 },
  { wavelength: 392.0, intensity: 12 },
  { wavelength: 393.6, intensity: 95 },
  { wavelength: 394.0, intensity: 70 },
  { wavelength: 395.0, intensity: 30 },

  { wavelength: 420.0, intensity: 15 },
  { wavelength: 421.0, intensity: 35 },
  { wavelength: 422.9, intensity: 120 },
  { wavelength: 423.5, intensity: 80 },
  { wavelength: 424.0, intensity: 40 },

  { wavelength: 426.0, intensity: 30 },
  { wavelength: 426.7, intensity: 90 },
  { wavelength: 427.0, intensity: 65 },

  { wavelength: 434.6, intensity: 110 },
  { wavelength: 435.0, intensity: 85 },
  { wavelength: 436.0, intensity: 40 },

  { wavelength: 438.0, intensity: 50 },
  { wavelength: 438.7, intensity: 95 },
  { wavelength: 439.0, intensity: 60 },

  { wavelength: 447.0, intensity: 70 },
  { wavelength: 447.3, intensity: 105 },
  { wavelength: 448.0, intensity: 80 },

  { wavelength: 480.0, intensity: 20 },
  { wavelength: 485.5, intensity: 60 },
  { wavelength: 486.2, intensity: 130 },
  { wavelength: 487.0, intensity: 90 },

  { wavelength: 516.5, intensity: 55 },
  { wavelength: 517.8, intensity: 125 },
  { wavelength: 518.0, intensity: 90 },

  { wavelength: 525.5, intensity: 50 },
  { wavelength: 526.6, intensity: 120 },
  { wavelength: 527.0, intensity: 80 },

  { wavelength: 580.0, intensity: 30 },
  { wavelength: 587.3, intensity: 140 },
  { wavelength: 588.0, intensity: 110 },

  { wavelength: 589.9, intensity: 150 },
  { wavelength: 590.0, intensity: 130 },
  { wavelength: 591.0, intensity: 70 },

  { wavelength: 650.0, intensity: 30 },
  { wavelength: 655.5, intensity: 70 },
  { wavelength: 656.6, intensity: 145 },
  { wavelength: 657.0, intensity: 120 },

  { wavelength: 658.6, intensity: 95 },
  { wavelength: 659.0, intensity: 70 },

  { wavelength: 770.0, intensity: 40 },
  { wavelength: 776.5, intensity: 95 },
  { wavelength: 777.1, intensity: 160 },
  { wavelength: 778.0, intensity: 120 }
];


/***********************
 * DOM ELEMENTS
 ***********************/
const fileInput = document.getElementById("file-input");
const spectrumDiv = document.getElementById("spectrum-input");
const analyzeBtn = document.getElementById("analyze-btn");
const outputDiv = document.getElementById("analysis-output");

/***********************
 * FILE UPLOAD SIMULATION
 ***********************/
fileInput.addEventListener("change", () => {
  spectrumDiv.classList.remove("hidden");
  analyzeBtn.disabled = false;
  renderSpectrum(fakeSpectrum);
});

/***********************
 * RENDER SPECTRUM INPUT
 ***********************/
function renderSpectrum(data) {
  spectrumDiv.innerHTML = "";

  data.forEach(p => {
    const line = document.createElement("div");
    line.className = "spectrum-line";
    line.textContent =
      `${p.wavelength.toFixed(1).padStart(6)} , ${p.intensity.toFixed(2)}`;
    spectrumDiv.appendChild(line);
  });
}

/***********************
 * FAKE ANALYSIS
 ***********************/
analyzeBtn.addEventListener("click", () => {
  outputDiv.innerHTML = "";

  fakeResults.forEach(r => {
    const div = document.createElement("div");
    div.className = "result";

    div.innerHTML = `
      <strong>${r.element}</strong> — ${r.wavelength} nm<br>
      Probability: ${r.probability}%
      <div class="bar">
        <div class="bar-fill" style="width:${r.probability}%"></div>
      </div>
    `;

    outputDiv.appendChild(div);
  });
});
