max = voti[0];
min = voti[0];
media = voti[0];
for(i = 0;i <= 5; i++) {
  if(voti[i]>max)
    max = voti[i];
  else
    if(voti[i]<min)
      min = voti[i];
 media = media+voti[i];
}
