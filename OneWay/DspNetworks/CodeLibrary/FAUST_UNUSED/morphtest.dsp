import("stdfaust.lib");
import("analyzers.lib");
//("basics.lib");

// Morphing weights with sliders
alpha = hslider("Alpha [0-1]", 0.25, 0, 1, 0.01);
beta  = hslider("Beta [0-1]", 0.25, 0, 1, 0.01);
gamma = hslider("Gamma [0-1]", 0.25, 0, 1, 0.01);
delta = hslider("Delta [0-1]", 0.25, 0, 1, 0.01);

// Normalize weights
totalWeight = alpha + beta + gamma + delta + 0.0001; // Avoid division by zero
normAlpha = alpha / totalWeight;
normBeta  = beta / totalWeight;
normGamma = gamma / totalWeight;
normDelta = delta / totalWeight;

// FFT size
fftSize = 1024;

// Input sources
input1 = _; // Input 1 (from HISE routing)
input2 = _; // Input 2
input3 = _; // Input 3
input4 = _; // Input 4

// Spectral processing for each input
spectra1 = input1 : fft(fftSize) : *(normAlpha);
spectra2 = input2 : fft(fftSize) : *(normBeta);
spectra3 = input3 : fft(fftSize) : *(normGamma);
spectra4 = input4 : fft(fftSize) : *(normDelta);

// Combine spectra and reconstruct audio
combinedSpectra = (spectra1 + spectra2 + spectra3 + spectra4) / 4;

// Main processing block
process = combinedSpectra : ifft;