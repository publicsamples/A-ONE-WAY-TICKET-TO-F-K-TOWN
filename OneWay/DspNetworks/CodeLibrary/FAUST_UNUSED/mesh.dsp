// Faust Source File: mesh
// Created with HISE on 2024-12-03
import("stdfaust.lib");
mesh_square_test(N,x) = mesh_square(N)~(busi(4*N,x)) // input to corner
with { 
    busi(N,x) = bus(N) : par(i,N,*(-1)) : par(i,N-1,_), +(x); 
};
process = 1-1' : mesh_square_test(4); // all modes excited forever

