clc;
clear all;
close all;

% histograms of raw data

% our queue
our_en_dur = [4614 540 242 197 188 191 227 194 211 202 196 191 183 191 194 222 187 200 242 185 179 145 153 153 151 149 141 152 149 149 149 153 149 177 146 147 153 151 145 149 143 143 151 144 147 149 141 153 143 151 151 143 143 149 147 149 151 149 147 143 151 149 144 138 149 151 153 149 147 142 140 147 147 144 149 149 142 149 149 150 147 178 149 150 146 145 143 138 182 142 151 144 149 140 149 143 148 184 151 148 146 190 151 146 145 147 145 175 144 145 150 150 150 150 149 145 149 145 144 153 176 149 144 175 147 147 156 153 151 149 191 153 192 152 153 151 147 153 151 138 149 184 180 149 144 142 151 149 151 149 140 145 142 148 146 148 146 143 150 146 141 140 147 143 143 148 151 151 148 149 149 149 140 149 151 145 151 147 143 145 140 138 145 149 138 149 141 140 143 147 143 149 143 147 149 140 140 172 151 145 150 149 149 148 149 143 145 146 144 148 151 138 145 149 149 144 149 149 150 145 151 147 146 145 142 3606 293 151 149 148 151 144 147 149 144 149 191 149 143 144 140 149 150 149 149 147 147 148 148 140 147 142 143 149 150 149 151 147 149 144 142 150 149 142 149 149 147 141 150 149 149 149 149 150 143 148 151 142 142 140 148 149 147 144 149 141 147 148 147 142 151 149 145 141 147 150 144 147 150 149 142 147 142 143 149 143 143 147 149 142 149 151 147 146 145 144 267 149 183 149 206 147 148 142 143 145 146 147 146 149 142 151 149 148 143 149 144 144 149 149 149 149 149 149 147 149 151 151 151 142 146 143 144 145 143 143 145 143 149 151 149 149 151 149 149 149 149 144 150 144 149 149 149 149 145 180 191 158 162 175 149 153 159 152 151 191 158 155 191 154 151 153 151 155 153 143 143 179 179 149 153 151 154 147 148 153 147 144 153 153 152 153 149 153 152 151 141 144 145 149 148 144 149 150 143 144 181 149 145 149 148 147 149 148 151 151 149 140 147 143 144 144 142 143 147 143 144 149 149 149 149 149 143 142 147 141 142 147 144 147 150 149 149 147 149 149 148 149 144 151 150 148 149 142 143 147 143 151 143 147 145 2831 276 153 147 149 143 149 149 149 141 146 177 148 146 145 140 147 148 145 150 150 143 143 149 144 148 142 149 151 148 149 141 142 149 144 149 151 142 149 144 149 151 150 142 151 143 151 149 146 149 150 146 149 149 143 149 151 143 151 151 150 149 148 144 140 141 150 149 149 149 150 142 146 191 149 147 148 143 202 140 145 145 149 150 151 150 144 147 144 149 151 150 151 147 145 141 150 187 151 149 143 143 149 145 151 143 153 147 144 150 147 151 149 143 151 149 147 142 149 149 149 148 149 142 149 149 147 145 147 150 149 144 149 141 147 144 143 151 142 149 150 147 149 143 151 149 149 149 144 147 178 188 150 149 243 240 149 158 148 155 155 197 151 184 154 150 149 150 155 153 149 140 149 178 149 149 153 140 149 146 145 149 144 143 151 153 144 150 149 149 141 149 144 148 149 149 148 147 146 149 150 151 147 151 182 145 151 149 144 151 149 144 149 149 150 151 149 149 149 144 149 144 149 151 149 147 144 149 148 151 149 142 151 149 147 143 144 142 138 145 140 149 147 149 143 149 149 145 149 142 150 142 147 142 149 144 2758 258 164 146 151 143 146 143 149 147 144 149 149 143 151 151 147 149 150 174 147 149 142 142 149 150 150 149 148 149 151 142 149 149 147 149 140 149 145 149 145 143 145 149 143 148 151 149 149 143 149 147 151 149 144 149 144 149 149 145 147 143 149 151 143 147 151 145 140 142 143 149 143 145 149 145 149 149 150 182 144 149 149 147 145 185 149 144 143 149 144 150 150 142 151 149 140 149 144 147 143 149 149 143 149 151 149 148 144 149 147 150 147 142 149 143 148 146 146 149 148 147 142 144 149 149 149 149 148 180 149 144 147 143 150 147 144 151 143 149 140 149 147 143 147 149 143 149 143 151 145 189 143 147 188 151 154 152 153 155 152 191 146 187 156 149 142 141 155 155 151 152 153 180 145 151 146 151 149 147 146 140 145 147 143 149 143 149 149 145 145 139 149 144 149 148 147 147 147 149 145 149 149 143 149 143 149 144 151 149 142 184 145 149 141 143 149 150 149 149 147 142 139 146 149 143 149 149 143 174 151 145 144 149 153 147 150 151 151 147 151 148 151 148 149 144 148 149 140 150 149 146 149 145 192 149 2497 256 156 143 149 151 147];
our_de_dur = [1481 604 278 440 272 220 233 213 209 226 224 235 237 220 237 237 224 244 215 204 202 215 200 201 205 202 200 202 198 209 200 192 202 222 198 200 201 220 203 199 198 202 195 200 198 233 202 201 200 227 200 198 204 222 197 195 198 198 198 200 196 219 200 200 197 231 220 222 199 202 198 202 200 194 195 198 194 198 197 200 200 198 202 200 198 198 198 196 202 200 202 196 204 202 203 200 202 215 200 195 200 202 202 196 199 198 195 198 196 198 202 198 197 203 191 198 199 202 194 208 203 204 198 198 200 195 198 198 196 213 209 199 198 202 200 194 200 202 200 202 204 193 197 199 198 200 202 195 196 201 195 197 200 196 200 202 198 198 206 200 198 218 198 196 199 200 198 199 204 196 189 202 194 191 206 198 198 198 200 200 200 202 202 200 198 198 203 198 200 202 197 198 203 207 198 198 197 199 202 198 198 200 200 200 202 200 200 200 197 192 203 198 197 198 198 198 201 198 197 202 202 198 196 204 200 216 198 191 200 212 201 200 200 198 197 202 190 200 199 196 198 202 198 199 200 196 198 202 195 200 200 198 199 204 199 199 261 211 201 197 189 202 198 201 200 197 196 202 191 199 200 190 199 202 202 200 198 196 197 201 194 199 202 199 200 198 198 189 197 213 196 200 196 197 200 195 194 196 195 194 198 200 200 198 198 200 191 195 200 198 200 191 198 197 198 198 194 194 208 193 199 211 200 260 196 196 200 189 195 200 193 197 200 196 198 200 196 196 198 191 198 202 200 199 198 198 198 198 198 193 198 198 197 207 192 253 185 189 189 200 195 196 200 202 200 202 195 199 198 202 194 195 200 195 198 200 192 198 199 194 197 198 198 195 200 207 200 200 200 200 197 202 195 204 202 198 202 200 197 200 195 200 200 198 200 199 198 200 198 198 195 197 200 195 196 198 197 213 198 198 200 198 199 199 199 200 195 200 200 195 196 200 199 200 198 192 198 200 198 190 199 194 196 202 196 196 200 196 198 211 191 198 197 200 194 193 198 193 202 198 198 200 200 196 198 200 194 199 198 197 197 200 196 198 198 197 199 202 199 200 200 203 255 193 194 200 192 199 198 200 194 200 195 198 199 190 198 200 195 197 198 190 197 200 198 199 200 189 202 200 200 198 199 204 196 200 198 202 196 198 199 208 199 199 192 198 199 194 199 198 200 196 200 195 196 200 196 198 197 200 198 199 200 197 196 211 194 195 200 200 198 200 198 198 200 194 192 196 199 200 200 196 200 198 189 200 201 199 192 198 194 200 200 200 198 198 202 205 194 196 198 197 200 199 198 191 199 199 187 200 198 191 192 200 198 200 198 195 198 198 196 198 200 192 198 200 193 198 198 202 194 196 200 196 199 198 196 198 198 200 197 198 184 194 198 194 200 191 194 204 200 200 200 187 199 199 199 198 202 198 198 209 202 198 198 200 204 204 200 202 200 200 200 201 203 190 208 200 198 202 206 200 203 192 196 190 202 205 200 200 200 200 201 246 196 191 200 200 200 200 198 198 208 198 198 210 198 200 200 193 196 192 200 202 198 199 192 199 200 194 189 200 196 200 195 217 188 200 192 198 200 195 193 200 195 200 200 198 200 204 198 196 200 196 198 199 198 196 200 264 195 193 200 197 197 192 199 224 200 197 196 198 198 195 198 199 200 198 198 194 197 198 198 194 198 202 198 198 201 196 198 200 191 198 200 198 202 193 198 207 198 200 199 198 200 198 199 198 191 200 200 195 198 200 196 200 200 200 198 198 196 192 198 195 200 200 198 196 202 191 199 212 200 198 200 200 195 198 200 195 198 200 192 199 200 198 198 202 190 194 200 201 200 200 198 194 198 198 193 199 198 194 198 211 200 198 198 196 198 200 202 197 200 200 196 200 198 198 198 199 200 198 198 198 196 200 202 192 196 199 195 198 198 197 198 211 197 200 200 197 199 198 196 198 190 200 200 204 200 187 193 195 200 198 200 200 196 196 200 198 198 200 189 198 200 198 196 213 199 197 190 200 259 197 198 198 195 198 200 200 196 198 195 200 198 198 199 198 198 198 200 198 200 198 196 198 196 198 200 206 197 200 197 200 198 198 198 198 194 200 198 198 197 196 200 196 196 200 200 196 198 200 196 196 200 200 196 200 196 197 200 207 198 198 190 198 198 200 187 195 200 196 201 192 198 200 198 190 200 195 190 196 193 200 202 187 190 200 189 198 200 198 200 211 200 195 193 200 185 322];

figure(1)
subplot(2,2,1)
histogram(our_en_dur);
ylabel('number of enqueues')
xlabel('duration (ns)')
title('our queue enqueue')

our_en_mean = mean(our_en_dur)
our_en_std_dev = std(our_en_dur)

subplot(2,2,2)
histogram(our_de_dur);
ylabel('number of dequeues')
xlabel('duration (ns)')
title('our queue dequeue')

our_de_mean = mean(our_de_dur)
our_de_std_dev = std(our_de_dur)

% their queue

their_en_dur = [42605 280 147 140 146 148 140 147 145 142 140 179 153 142 129 125 176 138 148 173 137 140 133 130 138 129 129 129 129 134 125 125 133 126 129 129 128 126 129 129 129 129 127 127 135 127 127 127 129 128 127 133 128 128 127 127 129 135 129 129 159 176 129 133 127 127 129 127 128 134 127 129 130 127 133 129 128 156 127 127 127 132 128 129 128 127 133 132 129 127 128 132 127 127 135 126 125 135 128 126 127 127 129 133 127 129 125 129 132 133 129 128 132 129 127 131 129 125 127 128 127 129 128 133 131 153 127 129 132 131 129 128 131 128 127 126 133 127 128 127 134 127 136 131 126 127 125 133 126 127 127 125 133 127 169 142 133 133 127 131 136 131 131 136 133 131 131 135 127 129 137 127 129 129 129 135 127 129 133 127 127 158 127 127 138 128 131 127 127 176 134 127 133 129 127 126 127 127 129 133 127 133 137 135 127 127 158 125 127 125 126 129 133 128 127 133 129 127 126 127 126 125 129 125 133 129 127 135 128 180 151 142 140 145 136 136 145 144 138 140 136 142 136 140 137 127 127 132 128 127 127 158 128 136 131 129 127 128 125 127 127 131 133 128 126 133 173 178 142 127 128 124 128 128 127 136 133 137 129 137 127 131 131 129 131 164 133 131 127 135 127 172 136 134 127 127 130 127 133 127 127 133 129 128 180 142 129 131 131 126 136 129 136 131 131 171 136 133 128 126 127 133 127 131 125 127 133 131 132 131 171 140 127 128 133 131 131 125 138 127 127 133 157 161 129 135 125 127 135 129 126 127 128 125 127 148 132 126 132 171 142 127 126 133 127 130 131 131 137 131 131 131 136 133 131 131 131 131 131 130 129 133 127 127 129 151 138 129 129 129 127 133 127 127 127 134 128 127 131 127 136 125 129 127 133 127 126 136 127 125 131 129 129 131 134 127 167 146 129 137 131 137 131 125 129 127 136 130 131 131 129 136 123 129 131 135 131 131 131 137 127 129 132 128 163 134 135 127 133 128 129 129 127 131 127 126 127 128 136 133 127 129 125 131 128 125 127 131 127 131 133 127 127 128 133 128 125 131 127 131 160 127 126 129 131 131 133 131 131 130 129 131 131 137 127 130 131 129 130 130 131 131 131 137 131 129 125 126 133 127 130 1800 3008 160 169 135 145 145 128 137 131 133 136 129 127 159 131 128 126 132 126 129 180 129 149 135 127 127 129 128 127 127 129 127 129 134 136 125 127 127 131 129 127 137 131 131 128 132 126 129 127 131 158 135 129 171 142 129 129 127 127 127 133 171 129 127 131 128 131 137 129 131 131 137 131 136 130 131 129 158 128 129 127 127 128 127 127 127 129 127 136 127 136 127 126 135 147 127 125 126 128 127 127 127 133 127 127 126 127 125 134 127 127 128 125 129 127 127 128 128 128 126 126 127 127 127 129 125 133 128 127 127 128 131 176 136 125 127 127 137 129 127 127 133 131 169 131 173 136 127 126 127 127 125 133 129 127 129 127 133 127 127 129 126 130 125 129 133 125 134 133 127 129 133 126 127 126 133 129 127 127 127 129 130 128 125 133 128 128 131 127 127 128 175 127 127 133 127 136 128 127 131 128 130 151 573 218 186 196 174 135 136 135 132 131 131 137 138 136 130 129 131 137 134 128 153 126 167 138 135 129 175 151 140 138 144 142 143 143 143 144 144 196 211 200 185 215 196 189 204 217 225 178 194 188 184 184 185 231 199 186 180 167 392 180 173 243 200 204 240 229 206 200 192 244 227 195 202 202 193 176 187 209 198 202 206 207 199 184 178 227 173 177 180 180 184 175 169 217 173 173 185 186 154 130 135 183 145 137 127 131 131 138 136 161 128 171 142 133 127 127 129 127 125 128 131 126 127 127 125 128 127 126 137 126 124 128 134 134 165 131 131 131 129 160 160 130 131 136 131 131 129 131 127 129 127 127 135 125 126 128 127 127 127 127 160 129 127 129 125 135 133 131 131 124 131 211 218 136 131 129 133 127 129 126 129 129 133 134 127 127 130 128 127 130 129 125 128 158 131 128 133 127 169 137 130 131 137 129 136 131 131 133 128 125 126 136 127 127 127 127 128 127 128 131 131 131 136 131 158 127 128 128 127 127 131 132 126 124 127 133 131 130 131 129 131 137 128 136 129 129 131 129 127 137 136 129 125 131 129 136 131 131 136 137 136 136 129 131 131 126 129 130 127 135 134 125 131 131 129 137 136 130 131 131 129 127 127 127 129];
their_de_dur = [272 86 80 77 80 76 76 77 71 71 76 73 78 74 75 75 76 77 76 77 79 78 78 78 79 76 77 76 78 78 78 77 79 78 71 73 76 78 78 79 77 78 77 77 77 78 78 77 77 78 78 76 78 73 78 77 77 71 73 76 71 73 76 78 76 78 76 80 76 80 76 76 78 76 78 76 77 76 76 76 78 77 80 77 78 77 78 78 77 80 78 78 78 78 76 76 78 77 76 74 78 77 76 76 76 76 78 77 76 77 79 78 77 74 77 77 78 74 76 77 77 76 80 77 76 75 79 76 77 78 77 74 76 76 78 76 76 71 76 78 78 80 73 77 76 78 78 78 78 76 76 79 76 79 76 77 78 71 77 78 76 76 78 76 76 76 77 76 76 77 76 71 71 76 76 76 75 73 76 76 69 77 78 78 77 76 78 76 78 78 76 76 79 76 76 76 76 77 74 76 79 78 76 76 77 78 78 73 77 80 79 76 76 78 77 76 76 80 80 78 76 76 77 78 78 69 75 78 76 78 76 69 73 74 78 71 75 77 76 76 75 78 75 76 78 77 75 76 76 76 78 71 77 73 78 75 77 76 76 69 76 76 76 76 76 75 73 76 79 78 78 78 77 77 77 76 76 69 76 76 77 76 74 78 77 75 78 77 74 78 78 77 78 76 78 77 78 76 76 78 78 79 77 80 78 80 77 78 76 76 77 77 76 77 76 77 76 76 76 78 77 77 77 76 71 77 76 76 78 76 76 78 78 77 78 69 78 78 78 76 79 80 78 76 79 71 77 80 75 78 78 76 73 76 76 77 78 78 76 78 76 76 77 76 77 78 78 78 77 77 76 71 71 79 79 77 76 78 78 77 76 78 77 76 78 78 78 78 77 78 78 77 78 74 78 75 76 76 76 78 77 76 80 76 78 78 71 78 78 76 76 79 77 74 76 76 77 76 77 76 79 78 76 77 71 77 78 76 78 77 76 78 77 76 76 78 75 78 77 77 73 77 78 74 75 78 71 78 79 76 78 77 76 71 78 78 78 77 77 76 76 78 76 76 71 75 78 78 77 77 77 77 75 79 71 77 76 77 76 74 71 75 76 76 76 76 77 76 78 77 77 76 78 76 76 78 76 74 76 78 79 76 74 79 76 76 76 75 76 76 77 77 77 75 78 71 76 76 78 78 77 76 78 71 75 76 76 75 76 75 78 78 74 76 76 78 77 78 76 78 77 78 78 78 77 77 80 77 76 76 73 75 76 77 78 79 76 77 74 76 78 76 71 79 74 76 75 74 77 77 76 76 76 78 78 76 79 75 77 78 74 76 76 76 76 77 78 76 76 74 79 76 76 77 77 78 69 71 75 77 73 76 78 78 77 77 80 71 78 76 76 76 76 78 77 76 69 76 73 74 73 71 78 76 74 76 76 78 77 78 76 76 76 77 77 76 79 75 76 78 79 76 75 77 76 71 75 77 76 76 77 76 75 78 76 71 77 78 75 77 78 78 77 77 73 75 76 77 76 76 77 76 78 76 79 74 74 78 77 77 76 76 73 71 77 76 77 77 71 77 76 79 76 77 76 79 76 76 78 78 78 76 76 77 76 76 77 77 77 79 76 76 76 73 74 76 78 71 77 78 74 78 80 77 78 76 76 76 78 78 79 75 78 76 76 78 78 76 77 78 71 78 76 76 76 78 77 77 78 76 80 78 76 78 76 78 75 76 76 73 71 76 71 71 78 71 78 71 77 78 78 77 80 78 78 80 79 78 80 78 77 77 76 76 78 71 71 76 76 79 76 71 76 78 78 76 80 76 80 78 80 80 76 76 74 74 76 77 76 79 69 76 78 73 77 76 77 76 76 78 76 76 77 76 78 78 79 79 78 76 76 76 76 69 77 75 77 78 78 78 76 76 77 76 76 77 77 79 77 75 78 75 78 77 76 71 77 79 78 76 78 76 77 77 76 79 76 78 77 76 76 76 77 71 71 69 78 78 78 79 76 78 78 79 79 80 75 80 76 78 79 78 79 73 80 71 77 78 75 74 80 76 76 76 78 79 76 77 76 78 78 76 76 76 77 76 77 78 78 77 77 77 71 77 76 71 73 77 78 76 80 76 77 78 78 78 78 71 77 76 75 78 75 76 78 78 76 76 76 77 76 76 78 76 71 78 78 80 79 78 79 78 77 76 76 76 78 80 74 75 74 71 77 76 77 76 76 78 78 78 76 77 75 78 76 78 69 78 75 78 78 76 76 77 79 76 77 75 78 77];

figure(2)
subplot(2,2,1)
histogram(their_en_dur);
ylabel('number of enqueues')
xlabel('duration (ns)')
title('std::queue enqueue')

their_en_mean = mean(their_en_dur)
their_en_std_dev = std(their_en_dur)

subplot(2,2,2)
histogram(their_de_dur);
ylabel('number of dequeues')
xlabel('duration (ns)')
title('std::queue dequeue')

their_de_mean = mean(their_de_dur)
their_de_std_dev = std(their_de_dur)

% remove outliers
our_en_dur2 = [];
lower = our_en_mean - 2*our_en_std_dev;
upper = our_en_mean + 2*our_en_std_dev;
for i = 1:length(our_en_dur)
 if (our_en_dur(i) >= lower) && (our_en_dur(i) <= upper)
    our_en_dur2(end + 1) = our_en_dur(i);
 end
end

% remove outliers
our_de_dur2 = [];
lower = our_de_mean - 2*our_de_std_dev;
upper = our_de_mean + 2*our_de_std_dev;
for i = 1:length(our_de_dur)
 if (our_de_dur(i) >= lower) && (our_de_dur(i) <= upper)
    our_de_dur2(end + 1) = our_de_dur(i);
 end
end

figure(1)
subplot(2,2,3)
histogram(our_en_dur2);
ylabel('number of enqueues')
xlabel('duration (ns)')
title('our queue enqueue (outliers removed)')

subplot(2,2,4)
histogram(our_de_dur2);
ylabel('number of dequeues')
xlabel('duration (ns)')
title('our queue dequeue (outliers removed)')

% remove outliers
their_en_dur2 = [];
lower = their_en_mean - 2*their_en_std_dev;
upper = their_en_mean + 2*their_en_std_dev;
for i = 1:length(their_en_dur)
 if (their_en_dur(i) >= lower) && (their_en_dur(i) <= upper)
    their_en_dur2(end + 1) = their_en_dur(i);
 end
end

% remove outliers
their_de_dur2 = [];
lower = their_de_mean - 2*their_de_std_dev;
upper = their_de_mean + 2*their_de_std_dev;
for i = 1:length(their_de_dur)
 if (their_de_dur(i) >= lower) && (their_de_dur(i) <= upper)
    their_de_dur2(end + 1) = their_de_dur(i);
 end
end

figure(2)
subplot(2,2,3)
histogram(their_en_dur2);
ylabel('number of enqueues')
xlabel('duration (ns)')
title('their queue enqueue (outliers removed)')

subplot(2,2,4)
histogram(their_de_dur2);
ylabel('number of dequeues')
xlabel('duration (ns)')
title('their queue dequeue (outliers removed)')
